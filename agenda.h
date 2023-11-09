#ifndef PROJET_C_AGENDA_H
#define PROJET_C_AGENDA_H

#include "rdv.h"

typedef struct {
    t_CONTACT ** contact_head;
}AGENDA;

AGENDA empty_agenda();

void insert_contact(AGENDA* agenda);

#endif //PROJET_C_AGENDA_H
