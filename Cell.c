//
// Created by lucbe on 26/10/2023.
//

#include "Cell.h"


// création d'un tableau de Cell
Cells *createCells(int height) {
    Cells *newCells = (Cells *) malloc(sizeof(Cells));
    newCells->cells = (Cell **) calloc(height, sizeof(Cell *));
    newCells->nbLevel = height;
    return newCells;
}

// création d'une Cell
Cell *createCell(int height, int value) {
    Cell *newCell = (Cell *) malloc(sizeof(Cell));
    newCell->next = createCells(height);
    newCell->value = value;
    return newCell;
}

// récupération du pointeur vers la Cell suivante dans le tableau de Cell d'une Cell
Cell *cellsGetAt(int index, Cells *cells) {
    if (index >= cells->nbLevel) {
        return NULL;
    }
    return cells->cells[index];
}

// ajout d'un pointeur vers une autre Cell dans le tableau de Cell d'une Cell
void cellsAddAt(Cells *cells, Cell *cell, int index) {
    if (index < cells->nbLevel) {
        cells->cells[index] = cell;
    }
}

// récupération de la taille du tableau de Cell d'une Cell
int getNbLevel(Cell *cell) {
    return cell->next->nbLevel;
}

// suppression d'une Cell
void deleteCell(Cell *cell) {
    for (int i = 0; i < cell->next->nbLevel; i++) {
        free(cell->next->cells[i]);
    }
    free(cell->next);
    free(cell);
}
