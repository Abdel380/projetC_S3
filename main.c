
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
    /*AGENDA  agenda =empty_agenda();
    p_CONTACT contact1 = create_contact();
    insert_contact(&agenda, contact1);


    p_CONTACT contact2 = create_contact();
    insert_contact(&agenda, contact2);

    p_CONTACT contact3 = create_contact();
    insert_contact(&agenda, contact3);
    */



    // AFFICHAGE DES NOMS ET DES NIVEAUX

    //display_agenda(agenda);
    p_CONTACT contact1 = create_contact();
    p_RDV rdv = create_rdv();
    Insert_rdv(rdv,contact1);
    display_Contact_rdv(*contact1);


    return 0;
}