#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "coordinates.h"

/* ABB:
 * Verify that the folder name matches the ABB archive naming convention
 *   UR<digits> - ABB
 * The prefix may be upper or lower case and the space-hyphen-space is required.
 */
TrajType fichier_ABB(const char *nom) {
    if (!nom)
        return (TrajType)-1;

    /* start with "UR" (case insensitive) */
    if (strncasecmp(nom, "UR", 2) != 0)
        return (TrajType)-1;

    const char *p = nom + 2;
    /* at least one digit must follow */
    if (!isdigit((unsigned char)*p))
        return (TrajType)-1;

    while (isdigit((unsigned char)*p))
        p++;

    /* expects " - ABB" and nothing after */
    if (strncmp(p, " - ABB", 6) != 0)
        return (TrajType)-1;

    p += 6;
    return *p == '\0' ? ABB : (TrajType)-1;
}

/* FANUC:
 * Verify if a name corresponds to traj*.ls or TRAJ*.LS 
 */ 
TrajType fichier_FANUC(const char *nom) {
    if (!nom)
        return (TrajType)-1;

    if (strncmp(nom, "traj", 4) != 0 && strncmp(nom, "TRAJ", 4) != 0)
        return (TrajType)-1;

    const char *ext = strrchr(nom, '.');
    if (!ext || (strcmp(ext, ".ls") != 0 && strcmp(ext, ".LS") != 0))
        return (TrajType)-1;

    /* Verify that the characters between "traj" and ".ls" are numbers */ 
    for (const char *p = nom + 4; p < ext; p++) {
        if (!isdigit((unsigned char)*p))
            return (TrajType)-1;
    }
    return FANUC;
}