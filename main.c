#include <stdio.h>
#include "list.h"
#include "timer.h"
#include "time.h"
#include "fonctions.h"

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

    char * name = scan_name();
    printf("%s", name);




    return 0;
}