//
// Created by alex on 24/10/2023.
//

#include "list.h"


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
    printf("[list head_%d @-]--", level);
    p_cell cell = lst.heads[0];
    while(lst.heads[level] != NULL){ // tete de niveau n'est pas a la fin
        printf(">[%d|@-]--",lst.heads[level]->value);
        lst.heads[level] = lst.heads[level]->nexts[level];
    }
    printf(">NULL\n");
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
    /*p_cell temp = lst->heads[0];
    p_cell prev = temp;
    while (temp->value < cell->value){
        prev = temp;
        temp = temp->nexts[0];
    }
    for (int i=0; i<level; i++){
        cell->nexts[i] = temp->nexts[i];
        prev->nexts[i] = cell;
    }*/






    /*p_cell temp = lst->heads[level-1];
    p_cell prev = NULL;

    if(cell->value < temp->value){ // si la valeur est plus petite que la tete
        add_head_list(lst,cell);
        return;


    }

    while (temp != NULL && cell->value > temp->value) {

        prev = temp; // stocke la val prec
        temp = temp->nexts[level-1]; // passe au suivant
    }


    if( temp != NULL) {
        prev->nexts[level-1] = cell;
        cell->nexts[level-1] = temp;

    }
    else{
        temp = cell;

    }*/

}


void insert_cell(t_list * lst, p_cell cell){
    p_cell temp = NULL; // Initialisation d'un pointeur temporaire à NULL

    for (int i = 0; i < cell->level; i++){ // Boucle parcourant les niveaux de la cellule
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






