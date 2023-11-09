#ifndef PROJET_C_RDV_CELL_H
#define PROJET_C_RDV_CELL_H

typedef struct{
    int jour;
    int mois;
    int annee;
}DATE;

typedef struct{
    int heure;
    int minutes;
}RDV_HORAIRE;

typedef struct{
    int heure;
    int minutes;
}RDV_DUREE;

typedef struct{
    char * contenu;
}RDV_OBJET;

typedef struct s_RDV
{
    DATE  * d;
    RDV_HORAIRE  * horaire;
    RDV_DUREE * duree;
    RDV_OBJET * objet;
    struct s_RDV * next; // tableau de pointeurs
} t_RDV, *p_RDV;


typedef struct s_CONTACT
{
    char * nom;
    p_RDV rdv_head;
    struct s_CONTACT ** nexts ; // tableau de pointeur
} t_CONTACT, *p_CONTACT;

#endif //PROJET_C_RDV_CELL_H