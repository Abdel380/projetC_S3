//
// Created by alex on 09/11/2023.
//

#include "agenda.h"

AGENDA empty_agenda(){
    AGENDA agenda;
    agenda.contact_heads = malloc(sizeof(agenda)*4);
    for(int i = 0;i<4;i++){
        *(agenda.contact_heads+i) = NULL;
    }
    return agenda;
}

void insert_contact(AGENDA* agenda,p_CONTACT contact){

    p_CONTACT next = agenda->contact_heads[0];
    p_CONTACT prev = next;

    if (strcmp(contact->nom, next->nom) < 0){ // Cas où le mot doit etre inserer au debut
        contact->nexts[0] = next;
        agenda->contact_heads[0] = contact;
    }
    else {
        while ((strcmp(contact->nom, next->nom) > 0) && (next->nexts[0] != NULL)) { // Parcours qui va au max jusqu'au dernier contact
            prev = next;
            next = next->nexts[0];







        }
        if ((strcmp(contact->nom, next->nom) > 0) && (next->nexts[0] == NULL)){
            next->nexts[0] = contact;
            contact->nexts[0] = NULL;
        }
        else { //
            prev->nexts[0] = contact;
            contact->nexts[0] = next;
        }
    }
}


void display_agenda_by_level(AGENDA agenda, int level){
    level--; // Par convention on affiche la ligne 0 pour le level un
    printf("[list head_%d @-]", level);
    p_CONTACT base = agenda.contact_heads[0];
    p_CONTACT cell = agenda.contact_heads[level];
    while (base != NULL){
        if (base == cell){
            printf("-->[%s|@-]",cell->nom);
            cell = cell->nexts[level];
        }
        else{
            printf("----------");
        }
        base = base->nexts[0];
    }
    printf("-->NULL\n");
}

void display_agenda(AGENDA agenda){
    for (int i=1; i<= 4; i++) {
        display_agenda_by_level(agenda, i);
    }
}


int dichotomie_research_contact(AGENDA agenda, p_CONTACT contact, char * nom){

    if( nom == contact->nom){
        return 1;
    }
   else if ((strcmp(contact->nom, nom) < 0) && (contact->level > 0)){

        for (int i=0; i < 4; i++){
            p_CONTACT temp = agenda.contact_heads[i];
            temp = contact->nexts[i];
        }
        return dichotomie_research_contact(agenda, contact->nexts[contact->level - 1], nom) != 0;
    }

    {
        return dichotomie_research_contact(agenda,agenda.contact_heads[contact->level - 1], nom) != 0;
    }
}