#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

#include "list.h"
#include "string.h"
#include "rdv_cell.h"

typedef struct {
    t_CONTACT ** contact_head;
}AGENDA;


p_CONTACT empty_contact();
char* scan_name();
void saisir_contact(p_CONTACT);

DATE* empty_date();

void saisir_date(DATE * );

p_CONTACT empty_contact();

void saisir_contact(p_CONTACT);

RDV_HORAIRE * empty_horaire();

void saisir_horaire(RDV_HORAIRE * );

RDV_DUREE * empty_duree();

void saisir_duree(RDV_DUREE * );

RDV_OBJET * empty_objet();

void saisir_objet(RDV_OBJET * );

char* scanstring(void);

void display_contact(t_CONTACT);

void display_date(DATE);

void display_horaire(RDV_HORAIRE);

void display_duree(RDV_DUREE);

void display_objet(RDV_OBJET);

void convert_maj_min(char * chaine);



p_RDV empty_rdv();

void saisir_rdv(p_RDV);

void display_rdv(t_RDV);


#endif //PROJET_C_FONCTIONS_H
