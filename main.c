
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
    AGENDA  agenda = empty_agenda();
    p_CONTACT contact1 = create_contact();
    insert_contact(&agenda, contact1);


    p_CONTACT contact2 = create_contact();
    insert_contact(&agenda, contact2);

    p_CONTACT contact3 = create_contact();
    insert_contact(&agenda, contact3);



    // AFFICHAGE DES NOMS ET DES NIVEAUX



   /*p_RDV rdv = malloc(sizeof(t_RDV));
    rdv->horaire.heure =  14;
    rdv->horaire.minutes = 25;

    rdv->d.annee = 2025;
    rdv->d.mois = 11;
    rdv->d.jour = 22;

    rdv->objet.contenu = "Blessure au mollet";

    rdv->duree.heure = 1;
    rdv->duree.minutes = 32;
    create_rdv_for_contact(rdv,&agenda);*/

    /*p_RDV rdv2 = malloc(sizeof(t_RDV));
    rdv2->horaire.heure =  15;
    rdv2->horaire.minutes = 38;

    rdv2->d.annee = 2024;
    rdv2->d.mois = 11;
    rdv2->d.jour = 22;

    rdv2->objet.contenu = "Blessure au genou";

    rdv2->duree.heure = 1;
    rdv2->duree.minutes = 10;*/






    display_agenda(agenda);

    p_CONTACT inconnu = research_contact(agenda.contact_heads[3], "dos_a", 3);
    if(inconnu == NULL){
        printf("pp");
    }else {
        printf("brrrr");
    }



    //p_RDV rdv1 = create_rdv();
    //create_rdv_for_contact(rdv1,&agenda);
    //p_RDV rdv2 = create_rdv();
    //Insert_rdv(rdv1,contact1);
    //Insert_rdv(rdv2,contact1);
    //printf("%d", number_rdv(*contact1));
    //display_Contact_rdv(*contact1);


    return 0;

}