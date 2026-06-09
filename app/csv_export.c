#include <stdio.h>
#include <stdlib.h>
#include "coords.h"

int csv_export(Trajectory traj) { 
    
    /* if TRAJECTORY is empty */
    if (traj.nb_points == 0) {
        printf("Aucune information extraite.\n");
        printf("Appuyez sur une touche pour fermer");
        /* waits for user input */
        getchar();
        return 0;
    }

    /* construct filename from provenance */
    char filename[512];
    snprintf(filename, sizeof(filename), "TrajectoryFrom_%s.csv", traj.provenance);

    /* create csv export file */
    FILE *csv = fopen(filename, "w");
    /* returns error if file is not properly created */
    if (!csv) {
        perror("Erreur lors de la creation du fichier\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 1;
    }
    /* (in csv) naming convention for the points */
    print_naming_convention(&traj);

    /* prints the coordinates in the csv */
    if (traj.nb_points > 0) {
        for (int i = 0; i < traj.nb_points; i++) {
            print_coord(&traj.points[i]);
        }
    }
    fclose(csv);

    printf("Donnees exportees avec succes dans '%s' !\n", filename);
    printf("Appuyez sur une touche pour fermer");
    /* waits for user input */
    getchar();
    return 0;
}

