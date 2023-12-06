#ifndef PROJET_C_agenda_H
#define PROJET_C_agenda_H

#include "rdv.h"

typedef struct {
    t_Contact ** contact_heads;
}Agenda;

Agenda empty_agenda();

void insert_contact(Agenda* agenda,p_Contact contact);
void insert_by_level(Agenda* agenda,p_Contact contact,int level, p_Contact temp, int level_next);

void display_agenda_by_level(Agenda agenda, int level);

void display_agenda(Agenda agenda);
p_Contact research_contact(p_Contact head, char * nom, int level);
void load_appointment_from_file(Agenda * agenda);
void create_rdv_for_contact(Agenda* agenda);
void load_contact_from_file(Agenda * agenda);



#endif //PROJET_C_agenda_H
