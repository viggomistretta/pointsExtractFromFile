#include <stdio.h>
#include "coords.h"

/* Portable version of strcasestr (searches hay for case-insensitive needle) cause it doesn't seem I can call it */
char *strcasestr_portable(const char *hay, const char *needle) {
    size_t nlen = strlen(needle);
    for (; *hay; hay++)
        if (strncasecmp(hay, needle, nlen) == 0)
            return (char *)hay;
    return NULL;
}

void print_naming_convention(const Coord *c) {
    switch (c->type) {
        case COORD_CARTESIAN:
            printf("Nom_Point,,X,Y,Z\n");
            break;
        case COORD_QUATERNION:
            printf("Nom_Point,,Q1,Q2,Q3,Q4\n");
            break;
        case COORD_ROTATION:
            printf("Nom_Point,,RX,RY,RZ\n");
            break;
    }
}

void print_coord(const Coord *c) {
    switch (c->type) {
        case COORD_CARTESIAN:
            printf("Cartésien : x=%.2f y=%.2f z=%.2f\n",
                   c->data.cartesian.x,
                   c->data.cartesian.y,
                   c->data.cartesian.z);
            break;
        case COORD_QUATERNION:
            printf("Quaternion : x=%.2f y=%.2f z=%.2f w=%.2f\n",
                   c->data.quaternion.x,
                   c->data.quaternion.y,
                   c->data.quaternion.z,
                   c->data.quaternion.w);
            break;
        case COORD_ROTATION:
            printf("Rotation : rx=%.2f ry=%.2f rz=%.2f\n",
                   c->data.rotation.rx,
                   c->data.rotation.ry,
                   c->data.rotation.rz);
            break;
    }
}