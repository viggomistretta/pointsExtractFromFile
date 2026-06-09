#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"

/* Forward declarations for type-specific handlers */
Trajectory type_ABB(const char *abbDir);
Trajectory type_FANUC(const char *fanucFile);

int main(void) {
    struct dirent *entry;
    DIR *dir = opendir(".");
    
    if (!dir) {
        perror("Erreur d'ouverture du repertoire courant");
        return 1;
    }

    int found = 0;

    /* Iterate through all files in current directory */
    while ((entry = readdir(dir)) != NULL) {
        TrajType type = (TrajType)-1;

        /* Check if file matches ABB naming convention */
        type = fichier_ABB(entry->d_name);
        if (type == ABB) {
            printf("Fichier ABB trouve : %s\n", entry->d_name);
            Trajectory traj = type_ABB(entry->d_name);
            csv_export(traj);
            found = 1;
            break;
        }

        /* Check if file matches FANUC naming convention */
        type = fichier_FANUC(entry->d_name);
        if (type == FANUC) {
            printf("Fichier FANUC trouve : %s\n", entry->d_name);
            Trajectory traj = type_FANUC(entry->d_name);
            csv_export(traj);
            found = 1;
            break;
        }
    }

    closedir(dir);

    if (!found) {
        printf("Aucun fichier de trajectoire trouve dans le repertoire.\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 0;
    }

    return 0;
}


