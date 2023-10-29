//
// Created by lucbe on 26/10/2023.
//

#include "List.h"

// création d'une List
List *createList(int maxLevel) {
    List *newList = (List *) malloc(sizeof(List));
    newList->heads = createCells(maxLevel);
    return newList;
}

// insertion d'une Cell dans une List
void insertCellInList(Cell *cell, List *list) {
    if (cell->next->nbLevel <= list->heads->nbLevel) {
        for (int i = 0; i < cell->next->nbLevel; i++) {
            list->heads->cells[i] = cell->next->cells[i];
        }
    }
}

// affichage d'un niveau de la List simplement
void displayOneLevelOfListSimply(List *list, int level) {
    if (level >= 0 && level < list->heads->nbLevel) {
        printf("[list head_%d @-] ", level);
        displayCellsSimply(list->heads->cells[level], level);
    }
}

// affichage d'un niveau de la List aligné
void displayOneLevelOfListAligned(List *list, int level) {
    if (level >= 0 && level < list->heads->nbLevel) {
        printf("[list head_%d @-] ", level);
        displayCellsAligned(list->heads->cells[0], level);
    }
}

// affichage de la List Simplement
void displayListSimply(List *list) {
    for (int i = 0; i < list->heads->nbLevel; i++) {
        displayOneLevelOfListSimply(list, i);
    }
}

void displayListAligned(List *list) {
    for (int i = 0; i < list->heads->nbLevel; i++) {
        displayOneLevelOfListAligned(list, i);
    }
}