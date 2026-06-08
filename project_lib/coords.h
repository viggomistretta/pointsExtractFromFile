#ifndef COORDINATES
#define COORDINATES

/* Types de coordonnées */

typedef enum {
    ABB,
    FANUC,
    KUKA,
} TrajType;

typedef enum {
    COORD_CARTESIAN,
    COORD_QUATERNION,
    COORD_ROTATION,
} CoordType;

typedef struct {
    float x, y, z;
} CartesianCoord;

typedef struct {
    float Q1, Q2, Q3, Q4;
} QuaternionCoord;

typedef struct {
    float rx, ry, rz;
} RotationCoord;

/* Coordonnée polymorphe */

typedef struct {
    CoordType type;
    union {
        CartesianCoord  cartesian;
        QuaternionCoord quaternion;
        RotationCoord   rotation;
    } data;
} Coord;

/* Point */

typedef struct {
    char  name[16];
    Coord coord;
} Point;

/* Trajectoire */

typedef struct {
    TrajType traj_type; /* type de trajectoire (ABB, FANUC, etc.) */
    char  *provenance;  /* arborescence fichier */
    int    nb_points;   /* nombre de points dans la trajectoire */
    Point *points;      /* tableau alloué dynamiquement */
} Trajectory;


/* utils_io */

char *strcasestr_portable(const char *hay, const char *needle);
void print_naming_convention(const Trajectory *t);
void print_coord(const Point *p);


/* get_file_type */

int est_fichier_ABB(const char *nom);
int est_fichier_FANUC(const char *nom);

#endif

