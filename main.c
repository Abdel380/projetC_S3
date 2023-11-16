
#include "list.h"
#include "timer.h"
#include "time.h"
#include "agenda.h"

int main() {
    /*int size = 10;
    int nb_recherche = 100000;
    int present;
    t_list lst2 = create_list(size);
    startTimer();
    for(int i = 0;i<nb_recherche;i++)
        present = dichotomie_research_cell(lst2, lst2.heads[size-1], 3);
    stopTimer();
    displayTime();*/

    // CREATION DE 3 CONTACT
    p_CONTACT contact1 = create_contact();
    p_CONTACT contact2 = create_contact();
    p_CONTACT contact3 = create_contact();
    contact1->nexts[0] = contact2;
    contact2->nexts[0] = contact3;

    AGENDA  agenda =empty_agenda();
    insert_contact(&agenda, contact1);
    insert_contact(&agenda, contact2);
    insert_contact(&agenda, contact3);

    p_CONTACT contactADD = create_contact();
    insert_contact(&agenda, contactADD);



    // AFFICHAGE DES NOMS ET DES NIVEAUX


    display_agenda(agenda);

    //printf("%d", dichotomie_research_contact(agenda,, ""))



    return 0;
}