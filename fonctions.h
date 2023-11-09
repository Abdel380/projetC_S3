//
// Created by alex on 24/10/2023.
//

#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

#include "list.h"
#include "string.h"

typedef struct{
    char * nom;
    char * prenom;
}CONTACT;

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

typedef struct{
    DATE  * d;
    RDV_HORAIRE  * horaire;
    RDV_DUREE * duree;
    RDV_OBJET * objet;
}RDV;


typedef struct sr_cell
{
    RDV* val;
    struct sr_cell ** nexts; // tableau de pointeurs

} r_cell, *pr_cell;


typedef struct sr_list{
    pr_cell head;

}tr_std_list;

typedef struct{
    CONTACT contact;
    tr_std_list *list_rdv;
}AGENDA;

CONTACT* empty_contact();

void saisir_contact(CONTACT * );

DATE* empty_date();

void saisir_date(DATE * );

CONTACT * empty_contact();

void saisir_contact(CONTACT * );

RDV_HORAIRE * empty_horaire();

void saisir_horaire(RDV_HORAIRE * );

RDV_DUREE * empty_duree();

void saisir_duree(RDV_DUREE * );

RDV_OBJET * empty_objet();

void saisir_objet(RDV_OBJET * );

char* scanstring(void);

void display_contact(CONTACT);

void display_date(DATE);

void display_horaire(RDV_HORAIRE);

void display_duree(RDV_DUREE);

void display_objet(RDV_OBJET);

void convert_maj_min(char*chaine);



RDV * empty_rdv();

void saisir_rdv(RDV *);

void display_rdv(RDV);


#endif //PROJET_C_FONCTIONS_H
