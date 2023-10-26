//
// Created by lucbe on 26/10/2023.
//

#include "Cell.h"

Cells *createCells(int height) {
    Cells *newCells = (Cells *) malloc(sizeof(Cells));
    newCells->cells = (Cell **) calloc(height , sizeof(Cell* ));
    newCells->nbLevel=height;
    return newCells;
}

Cell *createCell(int value, int height) {
    Cell *newCell = (Cell *) malloc(sizeof(Cell));
    newCell->nexts = createCells(height);
    newCell->value = value;
    return newCell;
}

Cell *cellsGetAt(int index, Cells *cells) {
    if(index>= cells->nbLevel){
        return NULL;
    }
    return cells->cells[index];
}

void cells_AddAt(Cells *cells, Cell* cell, int index){
    if (index < cells->nbLevel){
        cells->cells[index]=cell;
    }
}

int getNbLevel(Cell* cell){
    return cell->nexts->nbLevel;
}