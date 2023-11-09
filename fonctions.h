//
// Created by alex on 24/10/2023.
//

#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

#include "list.h"

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
    char * objet;
}RDV_OBJET;

typedef struct{
    DATE  d;
    RDV_HORAIRE  horaire;
    RDV_DUREE duree;
    RDV_OBJET objet;
}RDV;

DATE* initialise_date();

void saisir_date(DATE * );

CONTACT * initialise_contact();

void saisir_contact(CONTACT * );








#endif //PROJET_C_FONCTIONS_H
