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
    if (!abbDir || fichier_ABB(abbDir) != ABB) {
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
    return result;
}

/* extracts the points in the file */
int extraire_informations_fichier_ABB(Trajectory *traj, const char *traject) {
    FILE *f = fopen(traject, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier ABB");
        return 0;
    }

    size_t capacity = 16;
    traj->points = malloc(capacity * sizeof(*traj->points));
    if (!traj->points) {
        fclose(f);
        return 0;
    }

    int count = 0;
    char ligne[LINE_SIZE];
    int dans_point = 0;
    Point point;

    while (fgets(ligne, sizeof(ligne), f)) {
        if (strcasestr_portable(ligne, "CONST robtarget sre")) {
            memset(&point, 0, sizeof(point));
            dans_point = 1;

            char *debut_nom = strchr(ligne + 5, 'S');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, ':');
                if (fin_nom) {
                    size_t len = fin_nom - debut_nom;
                    if (len >= sizeof(point.name))
                        len = sizeof(point.name) - 1;
                    strncpy(point.name, debut_nom, len);
                    point.name[len] = '\0';
                }
            } else {
                strcpy(point.name, "Inconnu");
            }
            continue;
        }

        if (dans_point && strstr(ligne, "[[")) {
            double x, y, z;
            double q1, q2, q3, q4;
            if (sscanf(ligne, "%*[^[] [[%lf,%lf,%lf %*[^[] [%lf,%lf,%lf,%lf]",
                       &x, &y, &z, &q1, &q2, &q3, &q4) == 7) {
                point.coord.type = COORD_QUATERNION;
                point.coord.data.quaternion.Q1 = q1;
                point.coord.data.quaternion.Q2 = q2;
                point.coord.data.quaternion.Q3 = q3;
                point.coord.data.quaternion.Q4 = q4;

                if (count >= (int)capacity) {
                    size_t next_capacity = capacity * 2;
                    Point *next = realloc(traj->points, next_capacity * sizeof(*next));
                    if (!next) {
                        free(traj->points);
                        traj->points = NULL;
                        fclose(f);
                        return 0;
                    }
                    traj->points = next;
                    capacity = next_capacity;
                }
                traj->points[count++] = point;
            }
            dans_point = 0;
        }
    }

    fclose(f);
    traj->nb_points = count;
    return count;
}

/* seaches throughout the ABB directory to find trajectory files from which to extract points info */
int searchABB(void) {
    (void)printf;
    return 0;
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
    traj.nb_points = extraire_informations_fichier_ABB(&traj, traject_path);

    return traj;
}
