//
// Created by lucbe on 26/10/2023.
//

#include "Cell.h"

Cell *createCell(int height, int value) {
    Cell *newCell = (Cell *) malloc(sizeof(Cell));
    newCell->next = (Cell **) malloc(height * sizeof(Cell *));
    newCell->value = value;
    newCell->height = height;
    return newCell;
}