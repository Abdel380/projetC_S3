#ifndef PROJET_C_LIST_H
#define PROJET_C_LIST_H
#include "cell.h"

typedef struct s_list
{
    p_cell *heads; // tableau de pointeurs
    int max_level;
} t_list, *p_list;

t_list create_empty_list(int max_size);
void add_head_list(t_list * lst, p_cell cell);
void display_list_by_level(t_list lst, int level);
int get_size_list(t_list lst);
int * from_list_to_tab(t_list lst);
void display_list(t_list lst);
void insert_cell(t_list * lst, p_cell cell);


#endif //PROJET_C_LIST_H
