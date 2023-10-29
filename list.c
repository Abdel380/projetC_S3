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
    int * tab = from_list_to_tab(lst);
    int i;
    if (level == 0) {
        while(lst.heads[level] != NULL){ // tete de niveau n'est pas
            printf(">[%d|@-]--",lst.heads[level]->value);
            lst.heads[level] = lst.heads[level]->nexts[level];
        }
        printf(">NULL\n");
    }
    else{
        while(lst.heads[level] != NULL){ // tete de niveau n'est pas
            i = 0;
            while((tab[i] != lst.heads[level]->value) && (i< get_size_list(lst))){
                printf("---------");
                i++;
            }
            printf(">[%d|@-]--",lst.heads[level]->value);
            lst.heads[level] = lst.heads[level]->nexts[level];
        }
        printf(">NULL\n");
    }
}

int get_size_list(t_list lst){
    p_cell cell = lst.heads[0];
    int i = 1;
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

void insert_cell(t_list * lst, p_cell cell){
    int level = cell->level;
    p_cell * temp = lst->heads;
    p_cell prev = NULL;

    for ( int i = level-1; i >= 0; i--){

        if(cell->value <= temp[i]->value){ // si la valeur est plus petite que la tete
            add_head_list(lst,cell);
            break;
        }

        while (temp[i] != NULL && ){

            prev = temp[i]; // stocke la val prec
            temp[i] = temp[i]->nexts[i]; // passe au suivant



        }
    }


}
