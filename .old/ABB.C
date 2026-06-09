#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

/* limits the number of points to 100 */
#define MAX_INFOS 100 
/* limits the size of a "line" to 1024 */
#define LINE_SIZE 1024

typedef struct {
    char nom_point[100];
    double x;
    double y;
    double z;
    double Q1;
    double Q2;
    double Q3;
    double Q4;
    char type[20];   /* here the types are X_Y_Z & Q1_Q2_Q3_Q4 */
} Information; /* stocks the informations of the points(name,coordinates,type) */


/* Portable version of strcasestr (searches hay for case-insensitive needle) cause it doesn't seem I can call it */
char *strcasestr_portable(const char *hay, const char *needle) {
    size_t nlen = strlen(needle);
    for (; *hay; hay++)
        if (strncasecmp(hay, needle, nlen) == 0)
            return (char *)hay;
    return NULL;
}


/*
 * Verify that the folder name matches the ABB archive naming convention
 *   UR<digits> - ABB
 * The prefix may be upper or lower case and the space-hyphen-space is required.
 */
int est_fichier_ABB(const char *nom) {
    if (!nom)
        return 0;

    /* start with "UR" (case insensitive) */
    if (strncasecmp(nom, "UR", 2) != 0)
        return 0;

    const char *p = nom + 2;
    /* at least one digit must follow */
    if (!isdigit((unsigned char)*p))
        return 0;

    while (isdigit((unsigned char)*p))
        p++;

    /* expects " - ABB" and nothing after */
    if (strncmp(p, " - ABB", 6) != 0)
        return 0;

    p += 6;
    return *p == '\0';
}

/*
 * Open the BACKINFO/backinfo.txt file in the given ABB directory and look for
 * a line that references SYSMOD/TRAJECT.sys.  Those lines have the form
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
    return result;
}

/* extracts the points in the file */
int extraire_informations_fichier(const char *traject, Information infos[]) {
    
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
        printf(" X: %lf,\n", infos[i].x);
        printf(" Y: %lf,\n", infos[i].y);
        printf(" Z: %lf,\n", infos[i].z);
        printf(" Q1: %lf,\n", infos[i].Q1);
        printf(" Q2: %lf,\n", infos[i].Q2);
        printf(" Q3: %lf,\n", infos[i].Q3);
        printf(" Q4: %lf,\n\n", infos[i].Q4);
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
    for (int i = 0; i < nb_infos; i++) { 
        fprintf(csv, "%s,,%lf,%lf,%lf,,%lf,%lf,%lf,%.lf\n",
            infos[i].nom_point,
            infos[i].x,
            infos[i].y,
            infos[i].z,
            infos[i].Q1,
            infos[i].Q2,
            infos[i].Q3,
            infos[i].Q4);
    }
    fclose(csv);

    printf("Donnees exportees avec succes dans 'pointsTraj.csv' !\n");
    printf("Appuyez sur une touche pour fermer");
    /* waits for user input */
    getchar();
    return 0;
}



int main() { 
    searchABB();
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