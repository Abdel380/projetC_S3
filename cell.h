//
// Created by alex on 24/10/2023.
//

#ifndef PROJET_C_CELL_H
#define PROJET_C_CELL_H

#include <stdio.h>
#include <stdlib.h>


typedef struct s_cell
{
    int value;
    struct s_cell ** nexts; // tableau de pointeurs
    int level;
} t_cell, *p_cell;



p_cell createCell(int val,int level);
#endif //PROJET_C_CELL_H
