#include "list.h"
#include <time.h>

t_list create_empty_list(int max_size){
    t_list list;
    if ( max_size <= 0){
        max_size = 0;
    }
    list.max_level = max_size;
    list.heads = malloc(sizeof(p_cell)*max_size);// we allocate the memory we need to store the cells
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
    int * tab = calloc((power(2, size)-1) ,sizeof(int));
    int index = 0;

    for(int i = 0;i<size;i++){
        index = 0;
        while(index< power(2,size)){
            if(index!=0) {
                tab[index-1] = i;
            }
            index += power(2, i);
        }
    }

    if (size > 0){      // we create the list based on the array that contains the level of each cell
        p_cell temp;
        for (int i = 0; i<power(2, size)-1; i++){
            temp = createCell(i+1,tab[i]);
            insert_cell(&list, temp);
        }
    }
    return list;
}

void add_head_list(t_list * lst, p_cell cell) {
    if (lst->heads[0] == NULL){ // case of an empty list
        for (int i=0; i<cell->level;i++){ // change the head for all levels
            lst->heads[i] = cell;
        }
        return;
    }
    for (int i=0; i<cell->level;i++){ // case of a non-empty list
        cell->nexts[i] = lst->heads[i];
        lst->heads[i] = cell;
    }
}

void display_list_by_level(t_list lst, int level){
    level--; // By convention we display line 0 for level one
    printf("[list head_%d @-]", level);
    p_cell base = lst.heads[0];
    p_cell cell = lst.heads[level];
    while (base != NULL){
        if (base == cell){
            printf("-->[%d|@-]",cell->value); // display the value
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
    printf("-->NULL\n"); // for the end of the list
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
    for (int i=1; i<=lst.max_level; i++) { // we use a for loop for all levels
        display_list_by_level(lst, i);
    }
}





void insert_cell(t_list * lst, p_cell cell){
    p_cell temp = NULL; // initialisation of a NULL pointer

    for (int i = 0; i < cell->level+1; i++){ // loop that travel all the levels
        if (lst->heads[i] == NULL || lst->heads[i]->value >= cell->value) { // if the list is empty or if the head's value is superior or equal to the cell's value
            cell->nexts[i] = lst->heads[i]; // the cell become the new head of the list;
            lst->heads[i] = cell;
        } else {
            temp = lst->heads[i]; //temporary pointer to the head of the list
            while ((temp->nexts[i] != NULL) && (temp->nexts[i]->value < cell->value)) {
                //while the next element is not NULL and it's value is inferior to the cell value
                temp = temp->nexts[i]; // move foward in the list
            }
            cell->nexts[i] = temp->nexts[i]; // the cell point to the next cell
            temp->nexts[i] = cell; // the previous cell point to the cell
        }
    }
}

int level_0_research_cell(p_cell cell, int val){
    while ( cell != NULL){  // we move forward in the untill we find the value we search
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



int dichotomic_research_cell(t_list lst, p_cell cell, int value){

    if(value == cell->value){
        return 1;
    }
    if(value>power(2,lst.max_level)-1 || value<1){ //if the value is <1 or > to the value max in the list we return 0
        return 0;
    }
    else if ((cell->value < value) && (cell->level > 0)){ // if the value is in the second part of the list
        for (int i=0; i<lst.max_level; i++){ //we move the heads to the middle of the list
            p_cell temp = lst.heads[i];
            temp = cell->nexts[i];
        }
        return dichotomic_research_cell(lst, cell->nexts[cell->level - 1], value) != 0; // we change the level and go to the second part of the list
    }

    else if(cell->value> value && cell->level>0) {
        return dichotomic_research_cell(lst, lst.heads[cell->level - 1], value) != 0; // whe change the level and go the first cell
    }
}
int dichotomic_research(t_list list, int val){
    return dichotomic_research_cell(list,list.heads[list.max_level-1],val);
}


void timer_listNumber(int size_max){
    FILE *log_file = fopen("../log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;

    int level = 7;
    int random_number;
    while (level <= size_max){
        t_list lst = create_list(level);
        int found;
        srand((unsigned int)time(NULL));
        startTimer();
        for (int i=0; i<10000; i++){
            random_number = rand() % (power(2, level)-1);
            found = level_0_research_list(lst,random_number);

        }

        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer

        printf("Niveau %d\n==========\nStandard :",level);
        displayTime();

        startTimer();
        for (int i=0; i<10000; i++){
            random_number = rand() % (power(2, level)-1);

            found = dichotomic_research(lst, random_number);

        }
        stopTimer();
        time_all_levels = getTimeAsString();


        printf("==========\nDichotomique : ");

        displayTime();

        fprintf(log_file,format,level,time_lvl0, time_all_levels);

        level++;
    }

    fclose(log_file);
};