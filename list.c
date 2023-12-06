#include "list.h"
#include <time.h>

t_list create_empty_list(int max_size){
    t_list list;
    if ( max_size <= 0){
        max_size = 0;
    }
    list.max_level = max_size;
    list.heads = malloc(sizeof(p_cell)*max_size);
    for(int i = 0; i<max_size;i++){
        list.heads[i] = NULL;
    }

    return list;
}

int power(int a, int b){
    int result = 1;
    for (int i=0; i<b; i++)
        result = result * a;
    return result;
}

t_list create_list(int size){
    t_list list = create_empty_list(size);
    int * tab = calloc((power(2, size)-1) ,sizeof(int)); // On prend un tableau de power(2, size) valeur car on se passera de la première case mais on prendra une case en plus à la fin
    int indice = 0;

    for(int i = 0;i<size;i++){
        indice = 0;
        while(indice< power(2,size)){
            if(indice!=0) {
                tab[indice-1] = i;
            }
            indice += power(2, i);



        }
    }

    if (size > 0){
        p_cell temp;
        for (int i = 0; i<power(2, size)-1; i++){
            temp = createCell(i+1,tab[i]);
            insert_cell(&list, temp);
        }
    }
    return list;
}

void add_head_list(t_list * lst, p_cell cell) {
    if (lst->heads[0] == NULL){
        for (int i=0; i<cell->level;i++){
            lst->heads[i] = cell;
        }
        return;
    }
    for (int i=0; i<cell->level;i++){
        cell->nexts[i] = lst->heads[i];
        lst->heads[i] = cell;
    }
}

void display_list_by_level(t_list lst, int level){
    level--; // Par convention on affiche la ligne 0 pour le level un
    printf("[list head_%d @-]", level);
    p_cell base = lst.heads[0];
    p_cell cell = lst.heads[level];
    while (base != NULL){
        if (base == cell){
            printf("-->[%d|@-]",cell->value);
            cell = cell->nexts[level];
        }
        else{
            if (base->value < 10)
                printf("---------");
            else
                printf("----------");
        }
        base = base->nexts[0];
    }
    printf("-->NULL\n");
}

int get_size_list(t_list lst){
    p_cell cell = lst.heads[0];
    int i = 0;
    while(cell != NULL){
        cell = cell->nexts[0];
        i++;

    }
    return i;
}

int * from_list_to_tab(t_list lst){
    int * tab = calloc(get_size_list(lst)-1, sizeof(int));
    p_cell cell = lst.heads[0];
    int i = 0;
    while(cell != NULL){
        tab[i] = cell->value;
        cell = cell->nexts[0];
        i++;
    }
    return tab;
}

void display_list(t_list lst){
    for (int i=1; i<=lst.max_level; i++) {
        display_list_by_level(lst, i);
    }
}


void insert_cell_level(t_list * lst, p_cell cell, int level){
}


void insert_cell(t_list * lst, p_cell cell){
    p_cell temp = NULL; // Initialisation d'un pointeur temporaire à NULL

    for (int i = 0; i < cell->level+1; i++){ // Boucle parcourant les niveaux de la cellule
        if (lst->heads[i] == NULL || lst->heads[i]->value >= cell->value) { // Si la liste est vide ou si la valeur de la tête est supérieure ou égale à la valeur de la cellule
            cell->nexts[i] = lst->heads[i]; // La cellule devient la nouvelle tête de liste
            lst->heads[i] = cell;
        } else {
            temp = lst->heads[i]; // Pointeur temporaire pointe vers la tête de la liste
            while ((temp->nexts[i] != NULL) && (temp->nexts[i]->value < cell->value)) {
                // Tant que le prochain élément n'est pas NULL et que sa valeur est inférieure à celle de la cellule
                temp = temp->nexts[i]; // Avancer dans la liste
            }
            cell->nexts[i] = temp->nexts[i]; // La cellule pointe vers le prochain élément
            temp->nexts[i] = cell; // L'élément précédent pointe vers la cellule
        }
    }
}

int level_0_research_cell(p_cell cell, int val){


    while ( cell != NULL){
        if ( cell->value == val){
            return 1;
        }
        cell = cell->nexts[0];
    }

    return 0;
}

int level_0_research_list(t_list list, int val){

    return level_0_research_cell(list.heads[0], val);

}



int dichotomie_research_cell(t_list lst, p_cell cell, int value){

    if(value == cell->value){
        return 1;
    }
    if(value>power(2,lst.max_level)-1 || value<1){
        return 0;
    }
    else if ((cell->value < value) && (cell->level > 0)){
        for (int i=0; i<lst.max_level; i++){
            p_cell temp = lst.heads[i];
            temp = cell->nexts[i];
        }
        return dichotomie_research_cell(lst, cell->nexts[cell->level - 1], value) != 0;
    }

    else if(cell->value> value && cell->level>0) {
        return dichotomie_research_cell(lst, lst.heads[cell->level - 1], value) != 0;
    }
}



void timer_listNumber(int size_max){
    int size_temp = 7;
    int nombreAleatoire;
    while (size_temp <= size_max){
        t_list lst = create_list(size_temp);

        int find;

        startTimer();
        for (int i=0; i<10000; i++){
            nombreAleatoire = rand() % (power(2, size_temp)-1);
            find = dichotomie_research_cell(lst, lst.heads[size_temp-1], nombreAleatoire);
        }
        stopTimer();
        printf("Niveau %d\n==========\nDicotomique : ", size_temp);
        displayTime();

        startTimer();
        for (int i=0; i<10000; i++){
            nombreAleatoire = rand() % (power(2, size_temp)-1);
            find = dichotomie_research_cell(lst, lst.heads[size_temp-1], nombreAleatoire);
        }
        stopTimer();
        printf("==========\nStandart :");
        displayTime();

        size_temp++;
    }
};