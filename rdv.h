#ifndef PROJET_C_RDV_H
#define PROJET_C_RDV_H
#include "stdlib.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

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
    DATE d;
    RDV_HORAIRE horaire;
    RDV_DUREE duree;
    RDV_OBJET objet;
    struct s_RDV * next; // tableau de pointeurs
} t_RDV, *p_RDV;


typedef struct s_CONTACT
{
    char * nom;
    int level;
    p_RDV rdv_head; // tete de la liste
    struct s_CONTACT ** nexts ; // tableau de pointeur
} t_CONTACT, *p_CONTACT;

p_CONTACT empty_contact();
char* scan_name();
void cleanInputBuffer();
char* scanstring();
int compareDate(DATE date1, DATE date2);
int compareTime(RDV_HORAIRE time1, RDV_HORAIRE time2);

DATE empty_date();
DATE create_date();

p_CONTACT create_contact();
RDV_HORAIRE empty_horaire();
RDV_HORAIRE create_horaire();
RDV_DUREE empty_duree();
RDV_DUREE create_duree();
RDV_OBJET empty_objet();
RDV_OBJET create_objet();
void Insert_rdv(p_RDV rdv,p_CONTACT contact);


void display_contact(t_CONTACT);
void display_date(DATE);
void display_horaire(RDV_HORAIRE);
void display_duree(RDV_DUREE);
void display_objet(RDV_OBJET);
void convert_maj_min(char * chaine);
void display_Contact_rdv(t_CONTACT contact);




p_RDV empty_rdv();
p_RDV create_rdv();
void display_rdv(p_RDV);


#endif //PROJET_C_RDV_H