#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"

int main(int argc, char const *argv[]) {
    switch (get_file_type) {
    case "ABB":
        csv_export(type_ABB())
        break;

    case "FANUC":
        csv_export(type_FANUC())
        break;
        
    case "TMP":
        /* code */
        break;

    default:
        perror("No robots trajectoty found in directory")
        break;
    }
    return 0;
}


