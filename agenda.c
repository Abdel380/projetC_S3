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
    p_CONTACT temp = agenda->contact_heads[0];
    p_CONTACT prev = temp;


    if (temp == NULL){
        for (int i=0; i<4; i++)
            insert_by_level(agenda, contact, i, temp, 0);
    }
    else if (strcmp(contact->nom,temp->nom) < 0){
        int level_next;
        if (temp->nom[0] != contact->nom[0]){
            level_next = 3;
        }
        else if (temp->nom[0] == contact->nom[0] && temp->nom[1] != contact->nom[1]){
            level_next = 2;
        }
        else if (temp->nom[0] == contact->nom[0] && temp->nom[1] == contact->nom[1] && temp->nom[2] != contact->nom[2]){
            level_next = 1;
        }
        else {
            level_next = 0;
        }


        for (int i=0; i<4; i++)
            insert_by_level(agenda, contact, i, temp, level_next);
    }
    else{
        int level_next;
        while (strcmp(contact->nom, temp->nom) > 0 && temp->nexts[0] != NULL){
            prev = temp;
            temp = temp->nexts[0];
        }
        // Cas ou next->next = NULL et le contact > next
        if (strcmp(contact->nom, temp->nom) > 0 && temp->nexts[0] == NULL){
            prev = temp;
            temp = NULL;
            level_next = 0;
        }
        // for the next (non parcouru si on est au bout de la chaine)
        if (temp != NULL){
            if (temp->nom[0] != contact->nom[0]){
                level_next = 3;
            }
            else if (temp->nom[0] == contact->nom[0] && temp->nom[1] != contact->nom[1]){
                level_next = 2;
            }
            else if (temp->nom[0] == contact->nom[0] && temp->nom[1] == contact->nom[1] && temp->nom[2] != contact->nom[2]){
                level_next = 1;
            }
            else {
                level_next = 0;
            }
        }

        // prev
        if (prev->nom[0] != contact->nom[0]){
            for(int i=3; i>=0; i--)
                insert_by_level(agenda, contact, i, temp,  level_next);
        }
        else if (prev->nom[0] == contact->nom[0] && prev->nom[1] != contact->nom[1]){
            for (int i=2; i>=0; i--)
                insert_by_level(agenda, contact, i, temp, level_next);
        }
        else if (prev->nom[0] == contact->nom[0] && prev->nom[1] == contact->nom[1] && prev->nom[2] != contact->nom[2]){
            insert_by_level(agenda, contact, 0, temp, level_next);
            insert_by_level(agenda, contact, 1, temp, level_next);
        } else{
            insert_by_level(agenda, contact, 0, temp, level_next);
        }

    }
}
void insert_by_level(AGENDA* agenda,p_CONTACT contact,int level, p_CONTACT temp, int level_next){
    p_CONTACT next = NULL;
    next = agenda->contact_heads[level];
    p_CONTACT prev = next;
    if ( agenda->contact_heads[level] == NULL){ // la tete est vide
        agenda->contact_heads[level] = contact;
        contact->nexts[level] = NULL;
        return;
    }

    if ( agenda->contact_heads[level]->nexts[level] == NULL && strcmp(contact->nom,next->nom) > 0){ // si une seule cellule et on doit inserer Ã  droite
        agenda->contact_heads[level]->nexts[level] = contact;
        return;
    }

    if (strcmp(contact->nom,next->nom) < 0){  //on insere a gauche
        contact->nexts[level] = agenda->contact_heads[level];
        agenda->contact_heads[level] = contact;
        if (level <= level_next){
            contact->nexts[level] = temp;
        }
        else{
            contact->nexts[level] = temp->nexts[level];
        }

        return;
    }

    while ( next->nexts[level] != NULL && strcmp(contact->nom,next->nom) > 0 ){ // Soit next = Null soit on trouve l'emplacement ou inserer le contact
        prev = next;
        next = next->nexts[level];
    }

    if ( next->nexts[level] == NULL && strcmp(contact->nom,next->nom) > 0){ // si on insere a la fin
        next->nexts[level] = contact;
        contact->nexts[level] = NULL;
        return;
    }
    else if( next->nexts[level] == NULL && strcmp(contact->nom,next->nom) < 0){
        prev->nexts[level] = contact;
        if (level>level_next)
            contact->nexts[level] = NULL;
        else

            contact->nexts[level] = next;
        return;
    }

    // chainage pour les nexts
    if (level <= level_next){
        contact->nexts[level] = temp;
        printf("cacao");
    }
    else{
        contact->nexts[level] = temp->nexts[level]->nexts[level];
        temp->nexts[level] = NULL;
        temp->level = level_next;
    }


}

void display_agenda_by_level(AGENDA agenda, int level){
    level--; // Par convention on affiche la ligne 0 pour le level un
    printf("[list head_%d @-]", level);
    p_CONTACT base = agenda.contact_heads[0];
    p_CONTACT cell = agenda.contact_heads[level];
    while (base != NULL){
        if (base == cell){
            printf("-->[%s|%d|@-]",cell->nom, cell->level);
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


p_CONTACT research_contact(p_CONTACT head, char *nom, int level) {
    if (head == NULL){

        return NULL;
    }

    if (strcmp(head->nom, nom) > 0) {

        return NULL;
    }

    if (strcmp(nom, head->nom) == 0) {

        return head;
    }

    if (level == 3 && nom[0] > head->nom[0]) {

        head = head->nexts[3];
        return research_contact(head, nom, level);
    } else if (level == 3 && nom[0] == head->nom[0]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 2 && nom[1] != head->nom[1]) {

        head = head->nexts[2];
        return research_contact(head, nom, level);
    } else if (level == 2 && nom[1] == head->nom[1]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 1 && nom[2] != head->nom[2]) {

        head = head->nexts[1];
        return research_contact(head, nom, level);
    } else if (level == 1 && nom[2] == head->nom[2]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 0 && strcmp(head->nom, nom) < 0) {

        head = head->nexts[0];
        return research_contact(head, nom, level);
    }


    return NULL;  // Ajout d'une condition de retour par défaut
}

void create_rdv_for_contact(AGENDA *agenda) {
    char *nom = scan_name();

    // Recherche du contact dans l'agenda
    p_RDV rdv = create_rdv();
    p_CONTACT tmp = research_contact(agenda->contact_heads[3], nom, 3);
    //printf("%s",tmp->nom);
    if (tmp == NULL) {
        // Si le contact n'existe pas, créer un nouveau contact
        printf("popo455");
        p_CONTACT contact = empty_contact();


        contact->nom =  nom;


        insert_contact(agenda, contact);

        Insert_rdv(rdv, contact);
        //display_Contact_rdv(*contact);

        // Insérer le nouveau contact dans l'agenda

    } else {

        // Si le contact existe, insérer le rendez-vous

        Insert_rdv(rdv, tmp);
        //display_Contact_rdv(*tmp);

    }

}

