//
// Created by lucbe on 26/10/2023.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

typedef struct Cell {
    int value;
    struct Cells *next;
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

void displayCellsSimply(Cell *cell, int level);

void displayCellsAligned(Cell *cell, int level);

void deleteCell(Cell *cell);

#endif //PROJECT_CELL_H
