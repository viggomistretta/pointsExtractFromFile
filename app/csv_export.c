#include <stdio.h>
#include <stdlib.h>
#include "coordinates.h"

int main() { 
    
    /* if TRAJECTORY is empty */
    if (TRAJECTORY.nb_points == 0) {
        printf("Aucune information extraite.\n");
        printf("Appuyez sur une touche pour fermer");
        /* waits for user input */
        getchar();
        return 0;
    }

    /* create csv export file */
    FILE *csv = fopen("pointsTraj.csv", "w");
    /* returns error if file is not properly created */
    if (!csv) {
        perror("Erreur lors de la creation de pointsTraj.csv\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 1;
    }
    /* (in csv) naming convention for the points */
    fprintf(csv, "Nom_Point,,X,Y,Z,,Q1,Q2,Q3,Q4\n");

    /* prints the coordinates in the csv */
    if (TRAJECTORY)

    for (int i = 0; i < TRAJECTORY.nb_points; i++) { 
        print_coord(&TRAJECTORY.points[i].coord);
    }
    fclose(csv);

    printf("Donnees exportees avec succes dans 'pointsTraj.csv' !\n");
    printf("Appuyez sur une touche pour fermer");
    /* waits for user input */
    getchar();
    return 0;
}

