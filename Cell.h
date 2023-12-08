//
// Created by lucbe on 26/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Meeting.h"
#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

typedef struct Cell {
    int value;
    char nom_prenom[100];
    struct Cells *next;
    struct MeetingList *meeting;
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

void deleteCell(Cell *cell);

#endif //PROJECT_CELL_H
