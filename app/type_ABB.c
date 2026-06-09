#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"


/*
 * Open the BACKINFO/backinfo.txt file in the given ABB directory and look for
 * a line that references SYSMOD/TRAJECT.sys.  Those lines have the form:
 *
 *   SYSMOD/TRAJECT.sys @ ./back_ref/rapid/task0/sysmod/traject.sys
 *
 * We strip the leading "./back_ref/" (or just "./") and then prepend the
 * ABB directory name so that the caller receives a path such as
 *
 *   UR6011 - ABB/rapid/task0/sysmod/traject.sys
 *
 * The returned string must be freed by the caller.  If no valid entry is found
 * or the file cannot be opened, NULL is returned.
 */
char *construire_chemin_traject(const char *abbDir) {
    if (!est_fichier_ABB(abbDir)){
        printf("Impossible de trouver un fichier trajectoire dans %s\n", abbDir);
        getchar();
        return NULL;
    }

    /* searchs for the backinfo */
    char backinfo_path[LINE_SIZE];
    snprintf(backinfo_path, sizeof(backinfo_path), "%s/BACKINFO/backinfo.txt", abbDir);

    /* opens the backinfo and uses it as reference for trajectory files paths*/
    FILE *f = fopen(backinfo_path, "r");
    if (!f)
        return NULL;

    char line[1024];
    char *result = NULL;
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, "SYSMOD/TRAJECT.sys")) {
            char *at = strchr(line, '@');
            if (!at)
                continue;

            at++;
            while (*at && isspace((unsigned char)*at))
                at++;

            /* strip trailing whitespace/newline */
            char *end = at + strlen(at) - 1;
            while (end > at && isspace((unsigned char)*end))
                *end-- = '\0';

            /* remove leading "./" and optional "back_ref/" */
            if (strncmp(at, "./", 2) == 0)
                at += 2;
            if (strncmp(at, "back_ref/", 9) == 0)
                at += 9;

            /* build final path */
            size_t len = strlen(abbDir) + 1 + strlen(at) + 1;
            result = (char*) malloc(len);
            if (result)
                snprintf(result, len, "%s/%s", abbDir, at);
            break;
        }
    }

    fclose(f);
    Trajectory.arborescence = result;
    return result;
}

/* extracts the points in the file */
int extraire_informations_fichier(const char *traject) {
    
    /* open file, returns error if file is not found/not authorized */
    FILE *f = fopen(traject, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    char ligne[LINE_SIZE];
    int count = 0;
    Information info;
    int dans_point = 0;

    /* checks for the start of a line with a point in the file */
    while (fgets(ligne, sizeof(ligne), f)) {
        if (strcasestr_portable(ligne, "CONST robtarget sre")) {
            memset(&info, 0, sizeof(info));
            dans_point = 1;

            /* extract the name of the point out and saves in info.nom_point */
            char *debut_nom = strchr(ligne + 5, 'S');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, ':');
                if (fin_nom) {
                    size_t len = fin_nom - debut_nom;
                    strncpy(info.nom_point, debut_nom, len);
                    info.nom_point[len] = '\0';
                }
            }
        }
        
        /* if there is a point in the current line, registers the coordinates corresponding to said point */
        if (dans_point && strstr(ligne, "[[")) {
            if (sscanf(ligne, "%*[^[] [[%lf,%lf,%lf %*[^[] [%lf,%lf,%lf,%lf]",
                &info.x, 
                &info.y, 
                &info.z, 
                &info.Q1, 
                &info.Q2, 
                &info.Q3, 
                &info.Q4) == 7) {
                strcpy(info.type, "X_Y_Z-Q1_Q2_Q3_Q4");
                infos[count++] = info;
                dans_point = 0;
            }
        }
    }
    fclose(f);
    return count;
}

/* seaches throughout the ABB directory to find trajectory files from which to extract points info */
int searchABB() {
    struct dirent *entry;
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Erreur d'ouverture du repertoire courant");
        return 1;
    }

    /* takes the first one found */
    char abbDir[256] = "";
    while ((entry = readdir(dir)) != NULL) {
        if (est_fichier_ABB(entry->d_name)) {
            strcpy(abbDir, entry->d_name);
            break; 
        }
    }
    closedir(dir);

    /* ends search for ABB file if none are found in directory */
    if (abbDir[0] == '\0') { 
        printf("Aucun fichier ABB trouve dans le repertoire.\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 0;
    }

    printf("Fichier trouve : %s\n\n", abbDir);

    Information infos[MAX_INFOS];
    int nb_infos = extraire_informations_fichier(construire_chemin_traject(abbDir), infos);
}

/* Main wrapper function that processes ABB directory and returns Trajectory */
Trajectory type_ABB(const char *abbDir) {
    Trajectory traj;
    memset(&traj, 0, sizeof(traj));

    /* Check if directory matches ABB naming convention */
    if (fichier_ABB(abbDir) != ABB) {
        printf("Erreur: %s ne correspond pas au format ABB\n", abbDir);
        return traj;
    }

    /* Set trajectory metadata */
    traj.traj_type = ABB;

    /* Get the trajectory file path */
    char *traject_path = construire_chemin_traject(abbDir);
    if (!traject_path) {
        printf("Impossible de construire le chemin de trajectoire pour %s\n", abbDir);
        return traj;
    }

    /* Store the main ABB directory name as provenance */
    const char *sep = strstr(abbDir, " - ");
    size_t provenance_len = sep ? (size_t)(sep - abbDir) : strlen(abbDir);
    traj.provenance = malloc(provenance_len + 1);
    if (traj.provenance) {
        strncpy(traj.provenance, abbDir, provenance_len);
        traj.provenance[provenance_len] = '\0';
    }

    /* Store the full constructed trajectory path in arborescence */
    traj.arborescence = traject_path;

    /* Extract points from trajectory file */
    traj.nb_points = extraire_informations_fichier(traject_path);

    return traj;
}
