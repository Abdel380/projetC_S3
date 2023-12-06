#include "list.h"
#include "timer.h"
#include "time.h"
#include "menu.h"
#define MAXLINES 1000

int main() {
    /*int size = 4;
    t_list lst2 = create_list(size);
    display_list(lst2);
    printf("%d", level_0_research_list(lst2, -1));
    */

    /*startTimer();
    for(int i = 0;i<nb_recherche;i++)
        present = dichotomie_research_cell(lst2, lst2.heads[size-1], 3);
    stopTimer();
    displayTime();
     */
    timer_listNumber(16);



    // CREATION DE 3 CONTACT
    /*Agenda  agenda = empty_agenda();
    p_Contact contact1 = create_contact();
    insert_contact(&agenda, contact1);


    p_Contact contact2 = create_contact();
    insert_contact(&agenda, contact2);

    p_Contact contact3 = create_contact();
    insert_contact(&agenda, contact3);

    p_Contact contact4= create_contact();
    insert_contact(&agenda, contact4);

    display_agenda(agenda);
    */


    // AFFICHAGE DES NOMS ET DES NIVEAUX



   /*p_app rdv = malloc(sizeof(t_app));
    rdv->hour.heure =  14;
    rdv->hour.minute = 25;

    rdv->d.year = 2025;
    rdv->d.month = 11;
    rdv->d.day = 22;

    rdv->object.content = "Blessure au mollet";

    rdv->time.heure = 1;
    rdv->time.minute = 32;
    create_rdv_for_contact(rdv,&agenda);*/

    /*p_app rdv2 = malloc(sizeof(t_app));
    rdv2->hour.heure =  15;
    rdv2->hour.minute = 38;

    rdv2->d.year = 2024;
    rdv2->d.month = 11;
    rdv2->d.day = 22;

    rdv2->object.content = "Blessure au genou";

    rdv2->time.heure = 1;
    rdv2->time.minute = 10;*/



    //char * lign = "vzq_alex[popo,12/12/2024,12:30,1:30][popo2,12/12/2025,12:30,1:30]";
    //load_appointment_from_file();

    //p_app  rdv = get_appointment_characteristics(lign,name);
    //display_app(rdv);
    //printf("%s",name);




    //p_Contact contact = create_contact();


    //display_agenda(agenda);
    //create_rdv_for_contact(&agenda);
    //create_rdv_for_contact(&agenda);
    //save_appointment_to_file(contact1);

    //load_appointment_from_file(&agenda);
    //display_agenda(agenda);
   // p_Contact contact  = research_contact(agenda.contact_heads[3],"p_romain",3);
   // display_Contact_rdv(*contact);

    //create_rdv_for_contact(&agenda);
    //create_rdv_for_contact(&agenda);


    //p_app rdv2 = create_app();
   // insert_rdv(rdv2,contact3);
    //insert_rdv(rdv2,contact1);
    //printf("%d", number_rdv(*contact1));

    //display_app(search_rdv("popo2",contact2));
    //display_Contact_rdv(*contact3);
    //delete_appointment(contact3,contact3->app_head);
    //display_Contact_rdv(*contact3);
    //Agenda agenda = empty_agenda();
    //menu(&agenda);
    //create_empty_list()
    //load_contact_from_file( &agenda);

    //display_agenda(agenda);
    //t_list list = create_list(3 );
    //display_list(list);
    return 0;
}