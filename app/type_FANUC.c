#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"


/* extracts the points in the file */
int extraire_informations_fichier_FANUC(Trajectory *traj, const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier FANUC");
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
        if (strstr(ligne, "P[")) {
            memset(&point, 0, sizeof(point));
            dans_point = 1;

            char *debut_nom = strchr(ligne, '"');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, '"');
                if (fin_nom) {
                    size_t len = fin_nom - debut_nom;
                    if (len >= sizeof(point.name))
                        len = sizeof(point.name) - 1;
                    strncpy(point.name, debut_nom, len);
                    point.name[len] = '\0';
                }
            } else {
                char *num_debut = strchr(ligne, '[');
                char *num_fin = strchr(ligne, ']');
                if (num_debut && num_fin && num_fin > num_debut + 1) {
                    size_t len = num_fin - num_debut - 1;
                    if (len >= sizeof(point.name))
                        len = sizeof(point.name) - 1;
                    strncpy(point.name, num_debut + 1, len);
                    point.name[len] = '\0';
                } else {
                    strcpy(point.name, "Inconnu");
                }
            }
            continue;
        }

        if (dans_point && strstr(ligne, "RX =")) {
            double rx, ry, rz;
            if (sscanf(ligne, "%*[^R]RX = %lf mm%*[^R]RY = %lf mm%*[^R]RZ = %lf mm",
                       &rx, &ry, &rz) == 3) {
                point.coord.type = COORD_ROTATION;
                point.coord.data.rotation.rx = rx;
                point.coord.data.rotation.ry = ry;
                point.coord.data.rotation.rz = rz;

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
                dans_point = 0;
            }
        } else if (dans_point && strstr(ligne, "X =")) {
            double x, y, z;
            if (sscanf(ligne, "%*[^X]X = %lf mm%*[^Y]Y = %lf mm%*[^Z]Z = %lf mm",
                       &x, &y, &z) == 3) {
                point.coord.type = COORD_CARTESIAN;
                point.coord.data.cartesian.x = x;
                point.coord.data.cartesian.y = y;
                point.coord.data.cartesian.z = z;

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
                dans_point = 0;
            }
        }
    }

    fclose(f);
    traj->nb_points = count;
    return count;
}


/* seaches to find trajectory traject files from which to extract points info */
int searchFANUC(void) {
    (void)printf;
    return 0;
}

/* Main wrapper function that processes FANUC file and returns Trajectory */
Trajectory type_FANUC(const char *fanucFile) {
    Trajectory traj;
    memset(&traj, 0, sizeof(traj));

    /* Check if file matches FANUC naming convention */
    if (fichier_FANUC(fanucFile) != FANUC) {
        printf("Erreur: %s ne correspond pas au format FANUC\n", fanucFile);
        return traj;
    }

    /* Set trajectory metadata */
    traj.traj_type = FANUC;

    /* Store the main file name without extension as provenance */
    const char *dot = strrchr(fanucFile, '.');
    size_t provenance_len = dot ? (size_t)(dot - fanucFile) : strlen(fanucFile);
    traj.provenance = malloc(provenance_len + 1);
    if (traj.provenance) {
        strncpy(traj.provenance, fanucFile, provenance_len);
        traj.provenance[provenance_len] = '\0';
    }

    /* Store the file path in arborescence */
    traj.arborescence = malloc(strlen(fanucFile) + 1);
    if (traj.arborescence) {
        strcpy(traj.arborescence, fanucFile);
    }

    /* Extract points from trajectory file */
    traj.nb_points = extraire_informations_fichier_FANUC(&traj, fanucFile);

    return traj;
}
