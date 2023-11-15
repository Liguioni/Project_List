//
// Created by lucbe on 26/10/2023.
//

#include "Cell.h"

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

typedef struct List {
    Cells *heads;
} List;

List *createList(int maxLevel);

void insertCellInListFromHead(Cell *cell, List *list);

void displayOneLevelOfListSimply(List *list, int level);

void displayOneLevelOfListAligned(List *list, int level);

void displayListSimply(List *list);

void displayListAligned(List *list);

#endif //PROJECT_LIST_H
