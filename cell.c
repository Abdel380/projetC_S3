#include "cell.h"
#include <stdlib.h>


p_cell createCell(int val, int level){
    p_cell newcell = malloc(sizeof(t_cell));
    if ( level < 0){
        level = 0;
    }
    newcell->level = level;
    newcell->value = val;
    newcell->nexts = malloc((level+1) * sizeof(p_cell)); // allocates pointer array memory
    for(int i = 0; i < level+1; i++){
        *(newcell->nexts+i) = NULL; // set the pointers to NULL
    }
    return newcell;
}

