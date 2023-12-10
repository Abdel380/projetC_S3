#include "list.h"
#include "timer.h"
#include "time.h"
#include "menu.h"
#define MAXLINES 1000

int main() {
    // LISTE DE NIVEAU 4
    //t_list lst = create_list(4);
    //display_list(lst);

    // RECHERCHE D'UN NOMBRE DANS UNE LISTE DE NIVEAU 4
    //int valeur_chercher = 4;
    //printf("\n%d is find : %d\n", valeur_chercher,dichotomic_research(lst, valeur_chercher));

    // DEMONSTRATION DES DELAI + GRAPHIQUE
    //timer_listNumber(16);


    // -- PRESENTATION DE LA PARTIE 3 -- //
    // MENU
    Agenda agenda = empty_agenda();
    menu_partie3(&agenda);


    return 0;
}