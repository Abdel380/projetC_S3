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

        printf("%d", contact->nexts[level_next]->level);

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

    if ( agenda->contact_heads[level]->nexts[level] == NULL && strcmp(contact->nom,next->nom) > 0){ // si une seule cellule et on doit inserer à droite
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
    else{
        prev->nexts[level] = contact;
        contact->nexts[level] = next;
        return;
    }


    if (level <= level_next){
        contact->nexts[level] = temp;

    }
    else{
        contact->nexts[level] = temp->nexts[level];
    }
    if (temp->nom[level] != contact->nom[level]){
        for(int i=3; i>=0; i--){
            contact->nexts[level] = temp->nexts[level];
            temp->nexts[level] = NULL;

        }
        temp->level = 3;
    }
    else if (temp->nom[0] == contact->nom[0] && temp->nom[1] != contact->nom[1]){
        for (int i=2; i>=0; i--){
            contact->nexts[level] = temp->nexts[level];
            temp->nexts[level] = NULL;
        }
        temp->level = 2;
    }
    else if (temp->nom[0] == contact->nom[0] && temp->nom[1] == contact->nom[1] && temp->nom[2] != contact->nom[2]){
        for (int i=1; i>=0; i--){
            contact->nexts[level] = temp->nexts[level];
            temp->nexts[level] = NULL;
        }
        temp->level = 1;
    }
    else{
        contact->nexts[level] = temp->nexts[level];
        temp->nexts[level] = NULL;
        temp->level = 0;
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


/*int research_contact(AGENDA agenda, char * nom, int level, int indice){
    if (agenda.contact_heads[level] == NULL)
        return 0;
    else if (agenda.contact_heads[level]->nom[indice] > nom[indice])
        return 0;
    if ( nom == agenda.contact_heads[level]->nom){
        return 1;
    }
    if (level == 3 && nom[0] != agenda.contact_heads[3]->nom[0]){
        for (int i=0; i<=3; i++)
            agenda.contact_heads[i] = agenda.contact_heads[3]->nexts[3];
        return research_contact(agenda, nom, level, 0);
    } else if (level == 3 && nom[0] == agenda.contact_heads[3]->nom[0])
        return research_contact(agenda, nom, level-1, 1);

    if (level == 2 && nom[1] != agenda.contact_heads[2]->nom[0]){
        for (int i=0; i<=2; i++)
            agenda.contact_heads[i] = agenda.contact_heads[2]->nexts[2];
        return research_contact(agenda, nom, level, 1);
    } else if (level == 2 && nom[1] == agenda.contact_heads[2]->nom[1])
        return research_contact(agenda, nom, level-1, 2);


}*/
