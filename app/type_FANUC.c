#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"


/* extracts the points in the file */
int extraire_informations_fichier(const char *nom_fichier) {
    
    /* open file, returns error if file is not found */
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }

    char ligne[LINE_SIZE];
    Trajectory traj;
    strncpy(traj.provenance, nom_fichier, sizeof(traj.provenance));

    /* checks for the start of a line with a point in the file */
    while (fgets(ligne, sizeof(ligne), f)) {
        if (strstr(ligne, "P[")) {
            memset(&traj_rota, 0, sizeof(info));
            dans_point = 1;
            /* extract the name of the point out and saves in traj_rota.point.nom_point */
            char *debut_nom = strchr(ligne, '"');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, '"');
                if (fin_nom) {
                    Point p;
                    size_t len = fin_nom - debut_nom;
                    traj.p.nom_point[len] = '\0';
                }
            } 
            /* if name is unknown assigns "Inconnu" as name*/
            else {
                char *num_debut = strchr(ligne, '[');
                char *num_fin = strchr(ligne, ']');
                if (num_debut && num_fin && num_fin > num_debut + 1) {
                    Point p;
                    size_t len = num_fin - num_debut - 1;
                    strncpy(traj.p.nom_point, num_debut + 1, len);
                    traj.p.nom_point[len] = '\0';
                } else {
                    strcpy(traj.p.nom_point, "Inconnu");
                }
            }
        }

    /* if there is a point in the current line, registers the coordinates corresponding to said point */

        /* scans lines to find the points of type RX RY et RZ */
        if (dans_point && strstr(ligne, "RX =")) { 
            if (sscanf(ligne, "%*[^R]RX = %lf mm%*[^R]RY = %lf mm%*[^R]RZ = %lf mm", 
                    &traj.p.coord.data.rotation.x, 
                    &traj.p.coord.data.rotation.y, 
                    &traj.p.coord.data.rotation.z) == 3) {
                    traj.p.coord.type             = COORD_ROTATION;
            }
        }
        /* scan the lines to find the points of type X Y et Z */
        else if (dans_point && strstr(ligne, "X =")) { 
            if (sscanf(ligne, "%*[^R]X = %lf mm%*[^R]Y = %lf mm%*[^R]Z = %lf mm", 
                    &traj.p.coord.data.cartesian.x, 
                    &traj.p.coord.data.cartesian.y, 
                    &traj.p.coord.data.cartesian.z) == 3) {
                traj.p.coord.type = COORD_CARTESIAN;
            }
        }

    }

    fclose(f);
    return count;
}


/* seaches to find trajectory traject files from which to extract points info */
int searchFANUC() {
    struct dirent *entry;
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Erreur d'ouverture du repertoire courant");
        return 1;
    }

    /* takes the first one found */ /* need to change it to loop until all are processed */
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
}