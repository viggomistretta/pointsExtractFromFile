#ifndef COORDINATES
#define COORDINATES

/* === Types de coordonnées === */

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
    float rx, ry, rz;   /* angles d'Euler ou autre convention */
} RotationCoord;

/* === Coordonnée polymorphe === */

typedef struct {
    CoordType type;     /* le tag : indique ce qui est dans l'union */
    union {
        CartesianCoord  cartesian;
        QuaternionCoord quaternion;
        RotationCoord   rotation;
    } data;
} Coord;

/* === Point === */

typedef struct {
    char  name[16];     /* ex: "SRE9029" */
    Coord coord;
} Point;

/* === Trajectoire === */

typedef struct {
    char  *provenance;  /* arborescence fichier */
    int    nb_points;   /* nombre de points dans la trajectoire */
    Point *points;      /* tableau alloué dynamiquement */
} Trajectory;

/* utils_io */
char *strcasestr_portable(const char *hay, const char *needle);
void print_naming_convention(const Coord *c);
void print_coord(const Coord *c);

/* get_file_type */
int est_fichier_ABB(const char *nom);
int est_fichier_FANUC(const char *nom);

/* type_ABB */
char *construire_chemin_traject(const char *abbDir);
int extraire_informations_fichier(const char *traject, Information infos[]);
int searchABB();

/* type_FANUC */
int extraire_informations_fichier(const char *nom_fichier, Information infos[]);
int searchFANUC();



#endif

