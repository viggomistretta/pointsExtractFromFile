
int extraire_informations_fichier(const char *traject, Information infos[]) {
    FILE *f = fopen(traject, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }

    char ligne[LINE_SIZE];
    int count = 0;
    Information info;
    int dans_point = 0;

    while (fgets(ligne, sizeof(ligne), f)) {
        if (strstr(ligne, "CONST robtarget sre")) {
            memset(&info, 0, sizeof(info));
            dans_point = 1;

            char *debut_nom = strchr(ligne + 5, 'S');
            if (debut_nom) {
                debut_nom++;
                char *fin_nom = strchr(debut_nom, ':');
                if (fin_nom) {
                    size_t len = fin_nom - debut_nom - 1;
                    strncpy(info.nom_point, debut_nom, len);
                    info.nom_point[len] = '\0';
                }
            }
        }
        
        if (dans_point && strstr(ligne, "[[")) { // scan les lignes pour trouver les points de coordonnées
            if (sscanf(ligne, "%*[^[] [[%lf,%lf,%lf %*[^[] [%lf,%lf,%lf,%lf]",&info.x, &info.y, &info.z, &info.Q1, &info.Q2, &info.Q3, &info.Q4) == 7) {
                strcpy(info.type, "X_Y_Z-Q1_Q2_Q3_Q4");
                infos[count++] = info;
                dans_point = 0;
            }
        }
    }
    fclose(f);
    return count;
}

int searchABB() {
    struct dirent *entry;
    DIR *dir = opendir(checkTraject());
    if (!dir) {
        perror("Erreur d'ouverture du repertoire courant");
        return 1;
    }

    char fichier_traj[256] = "";
    while ((entry = readdir(dir)) != NULL) {
        if (est_fichier_ABB(entry->d_name)) {
            strcpy(fichier_traj, entry->d_name);
            break; // prend le premier trouve
        }
    }
    closedir(dir);

    if (fichier_traj[0] == '\0') { // Aucun fichier trouve
        printf("Aucun fichier 'traj*.ls' trouve dans le repertoire.\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 0;
    }

    printf("Fichier trouve : %s\n\n", fichier_traj);

    Information infos[MAX_INFOS];
    int nb_infos = extraire_informations_fichier(fichier_traj, infos);

    if (nb_infos == 0) {
        printf("Aucune information extraite.\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 0;
    }

    for (int i = 0; i < nb_infos; i++) { // Affiche dans le terminal les infos extraites
        printf("Nom_Point: %s\n", infos[i].nom_point);

        printf(" %s_mm: %.3f,\n", strcmp(infos[i].type, "XYZ") == 0 ? "X" : "RX", infos[i].rx);

        printf(" %s_mm: %.3f,\n", strcmp(infos[i].type, "XYZ") == 0 ? "Y" : "RY", infos[i].ry);

        printf(" %s_mm: %.3f,\n\n", strcmp(infos[i].type, "XYZ") == 0 ? "Z" : "RZ", infos[i].rz);
    }

    // Export CSV
    FILE *csv = fopen("pointsTraj.csv", "w");
    if (!csv) {
        perror("Erreur lors de la creation de points.csv\n");
        printf("Appuyez sur entree pour fermer");
        getchar();
        return 1;
    }

    fprintf(csv, "Nom_Point,%s_mm,%s_mm,%s_mm\n",
        strcmp(infos[0].type, "XYZ") == 0 ? "X" : "RX",
        strcmp(infos[0].type, "XYZ") == 0 ? "Y" : "RY",
        strcmp(infos[0].type, "XYZ") == 0 ? "Z" : "RZ");

    for (int i = 0; i < nb_infos; i++) {
        fprintf(csv, "P[%s],%.3f,%.3f,%.3f\n",
            infos[i].nom_point,
            infos[i].rx,
            infos[i].ry,
            infos[i].rz);
    }
    fclose(csv);


    printf("Donnees exportees avec succes dans 'pointsTraj.csv' !\n");

    printf("Appuyez sur entree pour fermer");
    getchar();
    return 0;
}
