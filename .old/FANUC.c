#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"

/* limits the number of points to 100 */
#define MAX_INFOS 100 
/* limits the size of a "line" to 1024 */
#define LINE_SIZE 1024

typedef struct {
    char nom_point[100];
    double rx;
    double ry;
    double rz;
    char type[20];   /* here the types are "RX_RY_RZ" or "XYZ" */ 
} Information; /* stocks the informations of the points(name,coordinates,type) */


/* Verify if a name corresponds to traj*.ls or TRAJ*.LS */ 
int est_fichier_traj(const char *nom) {
    if (strncmp(nom, "traj", 4) != 0 && strncmp(nom, "TRAJ", 4) != 0)
        return 0;

    const char *ext = strrchr(nom, '.');
    if (!ext || (strcmp(ext, ".ls") != 0 && strcmp(ext, ".LS") != 0))
        return 0;

    /* Verify that the characters between "traj" and ".ls" are numbers */ 
    for (const char *p = nom + 4; p < ext; p++) {
        if (!isdigit((unsigned char)*p))
            return 0;
    }
    return 1;
}

/* extracts the points in the file */
int extraire_informations_fichier(const char *nom_fichier, Information infos[]) {
    
    /* open file, returns error if file is not found */
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }

    char ligne[LINE_SIZE];
    int count = 0;
    Information info;
    int dans_point = 0;

    /* checks for the start of a line with a point in the file */
    while (fgets(ligne, sizeof(ligne), f)) {
        if (strstr(ligne, "P[")) {
            memset(&info, 0, sizeof(info));
            dans_point = 1;

            /* extract the name of the point out and saves in info.nom_point */
            char *debut_nom = strchr(ligne, '"');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, '"');
                if (fin_nom) {
                    size_t len = fin_nom - debut_nom;
                    strncpy(info.nom_point, debut_nom, len);
                    info.nom_point[len] = '\0';
                }
            } 
            /* if name is unknown assigns "Inconnu" as name*/
            else {
                char *num_debut = strchr(ligne, '[');
                char *num_fin = strchr(ligne, ']');
                if (num_debut && num_fin && num_fin > num_debut + 1) {
                    size_t len = num_fin - num_debut - 1;
                    strncpy(info.nom_point, num_debut + 1, len);
                    info.nom_point[len] = '\0';
                } else {
                    strcpy(info.nom_point, "Inconnu");
                }
            }
        }

        /* if there is a point in the current line, registers the coordinates corresponding to said point */

        /* scans lines to find the points of type RX RY et RZ */
        if (dans_point && strstr(ligne, "RX =")) { 
            if (sscanf(ligne, "%*[^R]RX = %lf mm%*[^R]RY = %lf mm%*[^R]RZ = %lf mm", &info.rx, &info.ry, &info.rz) == 3) {
                strcpy(info.type, "RX_RY_RZ");
                infos[count++] = info;
                dans_point = 0;
            }
        }
        /* scan the lines to find the points of type X Y et Z */
        else if (dans_point && strstr(ligne, "X =")) {  
            if (sscanf(ligne, "%*[^X]X = %lf mm%*[^Y]Y = %lf mm%*[^Z]Z = %lf mm",&info.rx, &info.ry, &info.rz) == 3) {
                strcpy(info.type, "XYZ");
                infos[count++] = info;
                dans_point = 0;
            }
        }

    }

    fclose(f);
    return count;
}
/* seaches to find trajectory traject files from which to extract points info */
int searchFanuc() {
    struct dirent *entry;
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Erreur d'ouverture du repertoire courant");
        return 1;
    }

    /* takes the first one found */
    char fichier_traj[256] = "";
    while ((entry = readdir(dir)) != NULL) {
        if (est_fichier_traj(entry->d_name)) {
            strcpy(fichier_traj, entry->d_name);
            break; 
        }
    }
    closedir(dir);

    /* ends search for traj*ls file if none are found in directory */
    if (fichier_traj[0] == '\0') { 
        printf("Aucun fichier 'traj*.ls' trouve dans le repertoire.\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 0;
    }

    printf("Fichier trouve : %s\n\n", fichier_traj);

    Information infos[MAX_INFOS];
    int nb_infos = extraire_informations_fichier(fichier_traj, infos);

    /* if no points are in trajectory file end search */
    if (nb_infos == 0) {
        printf("Aucune information extraite.\n");
        printf("Appuyez sur une touche pour fermer");
        /* waits for user input */
        getchar();
        return 0;
    }

    /* in terminal, prints the points that are extracted */
    for (int i = 0; i < nb_infos; i++) { 
        printf("Nom_Point: %s\n", infos[i].nom_point);

        printf(" %s_mm: %lf,\n", strcmp(infos[i].type, "XYZ") == 0 ? "X" : "RX", infos[i].rx);

        printf(" %s_mm: %lf,\n", strcmp(infos[i].type, "XYZ") == 0 ? "Y" : "RY", infos[i].ry);

        printf(" %s_mm: %lf,\n\n", strcmp(infos[i].type, "XYZ") == 0 ? "Z" : "RZ", infos[i].rz);
    }

    /* create csv export file */
    FILE *csv = fopen("pointsTraj.csv", "w");
    /* returns error if file is not properly created */
    if (!csv) {
        perror("Erreur lors de la creation de points.csv\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 1;
    }
    /* (in csv) naming convention for the points */
    fprintf(csv, "Nom_Point,%s_mm,%s_mm,%s_mm\n",
        strcmp(infos[0].type, "XYZ") == 0 ? "X" : "RX",
        strcmp(infos[0].type, "XYZ") == 0 ? "Y" : "RY",
        strcmp(infos[0].type, "XYZ") == 0 ? "Z" : "RZ");

    /* prints the coordinates in the csv */
    for (int i = 0; i < nb_infos; i++) {
        fprintf(csv, "P[%s],%lf,%lf,%lf\n",
            infos[i].nom_point,
            infos[i].rx,
            infos[i].ry,
            infos[i].rz);
    }
    fclose(csv);

    printf("Donnees exportees avec succes dans 'pointsTraj.csv' !\n");
    printf("Appuyez sur une touche pour fermer");
    /* waits for user input */
    getchar();
    return 0;
}


int main() {
    searchFanuc();
    /* Choix de la commande selon le système d'exploitation */
    #if defined(_WIN32)
        system("start pointsTraj.csv");
    #elif defined(__APPLE__)
        system("open pointsTraj.csv");
    #elif defined(__linux__)
        system("xdg-open pointsTraj.csv");
    #else
        printf("Ouverture automatique non supportée sur ce système.\n");
    #endif

    return 0;
}