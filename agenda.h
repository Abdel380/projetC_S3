#ifndef PROJET_C_AGENDA_H
#define PROJET_C_AGENDA_H

#include "rdv.h"

typedef struct {
    t_CONTACT ** contact_heads;
}AGENDA;

AGENDA empty_agenda();

void insert_contact(AGENDA* agenda,p_CONTACT contact);
void insert_by_level(AGENDA* agenda,p_CONTACT contact,int level, p_CONTACT temp, int level_next);

void display_agenda_by_level(AGENDA agenda, int level);

void display_agenda(AGENDA agenda);
int research_contact(p_CONTACT head, char * nom, int level);

#endif //PROJET_C_AGENDA_H
