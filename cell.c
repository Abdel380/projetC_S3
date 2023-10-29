#include "cell.h"
#include <stdlib.h>


p_cell createCell(int val, int level){
    p_cell newcell = malloc(sizeof(t_cell));
    if ( level < 0){
        level = 0;
    }
    newcell->level = level;
    newcell->value = val;
    newcell->nexts = malloc((level+1) * sizeof(p_cell)); // alloue la mémoire du tableau de pointeur
    for(int i = 0; i < level+1; i++){
        *(newcell->nexts+i) = NULL; // mets les pointeurs à NULL
    }
    return newcell;
}

