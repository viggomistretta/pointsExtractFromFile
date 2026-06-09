#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "coordinates.h"

/* Portable version of strcasestr (searches hay for case-insensitive needle) because it doesn't exist in windows */
char *strcasestr_portable(const char *hay, const char *needle) {
    size_t nlen = strlen(needle);
    for (; *hay; hay++)
        if (strncasecmp(hay, needle, nlen) == 0)
            return (char *)hay;
    return NULL;
}

void print_naming_convention(const Trajectory *t) {
    switch (t->traj_type) {
        case ABB:
            printf("Nom_Point,,Q1,Q2,Q3,Q4\n");
            break;
        case FANUC:
            printf("Nom_Point,,X,Y,Z\n");
            break;
        case KUKA:
            printf("Nom_Point,,RX,RY,RZ\n");
            break;
    }
}

void print_coord(const Point *p) {
    switch (p->coord.type) {
        case COORD_CARTESIAN:
            printf("%s,,%.2f,%.2f,%.2f\n",
                   p->name,
                   p->coord.data.cartesian.x,
                   p->coord.data.cartesian.y,
                   p->coord.data.cartesian.z);
            break;
        case COORD_QUATERNION:
            printf("%s,,%.2f,%.2f,%.2f,%.2f\n",
                   p->name,
                   p->coord.data.quaternion.Q1,
                   p->coord.data.quaternion.Q2,
                   p->coord.data.quaternion.Q3,
                   p->coord.data.quaternion.Q4);
            break;
        case COORD_ROTATION:
            printf("%s,,%.2f,%.2f,%.2f\n",
                   p->name,
                   p->coord.data.rotation.rx,
                   p->coord.data.rotation.ry,
                   p->coord.data.rotation.rz);
            break;
    }
}