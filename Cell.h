//
// Created by lucbe on 26/10/2023.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

#include "Cells.h"

typedef struct Cell {
    int value;
    Cells nexts;
} Cell;

Cell *createCell(int height, int value);

#endif //PROJECT_CELL_H
