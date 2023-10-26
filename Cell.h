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
    struct Cells *nexts;
} Cell;

typedef struct Cells {
    struct Cell **cells;
    int nbLevel;
} Cells;

Cell *createCell(int height, int value);

Cells *createCells(int height);

Cell *cellsGetAt(int index, Cells *cells);

void cellsAddAt(Cells *cells, Cell *cell, int index);

int getNbLevels(Cell *cell);

#endif //PROJECT_CELL_H
