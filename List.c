//
// Created by lucbe on 26/10/2023.
//

#include "List.h"
#include <math.h>

Cell *searchValueAtOneLevel(Cell *cell, int value, int level);

Cell *searchDichotomously(int value, int level, List *list, Cell *comparison);

Cell *searchPrevious(Cell *head, int value, int level);

// création d'une List
List *createList(int maxLevel) {
    List *newList = (List *) malloc(sizeof(List));
    newList->heads = createCells(maxLevel);
    return newList;
}

// insertion d'une Cell dans une List
void insertCellInListFromHead(Cell *cell, List *list) {
    for (int i = 0; i < cell->next->nbLevel; i++) {
        if (cell->next->nbLevel <= list->heads->nbLevel) {
            cell->next->cells[i] = list->heads->cells[i];
            list->heads->cells[i] = cell;
        }
    }
}

// affichage d'un niveau de la List simplement
void displayOneLevelOfListSimply(List *list, int level) {
    if (level >= 0 && level < list->heads->nbLevel) {
        printf("[list head_%d @-]", level);
        Cell *cell = list->heads->cells[level];
        while (cell != NULL) {
            printf("-->[ %d|@-]", cell->value);
            cell = cell->next->cells[level];
        }
        printf("-->NULL\n");
    }
}

// affichage d'un niveau de la List alignée
void displayOneLevelOfListAligned(List *list, int level) {
    if (level >= 0 && level < list->heads->nbLevel) {
        printf("[list head_%d @-]", level);
        Cell *nextCell = list->heads->cells[0];
        Cell *prevCell = NULL;
        while (nextCell != NULL) {
            if (nextCell->next->cells[level] == NULL && prevCell == NULL) {
                printf("-----------");
            } else {
                printf("-->[ %d|@-]", nextCell->value);
                prevCell = nextCell;
            }
            nextCell = nextCell->next->cells[0];
        }
        printf("-->NULL\n");
    }
}

// affichage de la List simplement
void displayListSimply(List *list) {
    for (int i = 0; i < list->heads->nbLevel; i++) {
        displayOneLevelOfListSimply(list, i);
    }
}

// affichage de la List alignée
void displayListAligned(List *list) {
    for (int i = 0; i < list->heads->nbLevel; i++) {
        displayOneLevelOfListAligned(list, i);
    }
}

// suppression d'une Cell d'une List
void deleteCellFromList(List *list, Cell *cell) {
    Cell *tmp = list->heads->cells[0];
    Cell *previous = NULL;
    while (tmp->value != cell->value || tmp != NULL) {
        previous = tmp;
        tmp = tmp->next->cells[0];
    }
    if (tmp != NULL) {
        for (int i = 0; i < tmp->next->nbLevel; i++) {
            previous->next->cells[i] = tmp->next->cells[i];
        }
        deleteCell(tmp);
    }
}

// suppression de la List
void deleteList(List *list) {
    while (list->heads->cells[0] != NULL) {
        for (int i = 0; i < list->heads->nbLevel; i++) {
            list->heads->cells[i] = list->heads->cells[i]->next->cells[i];
        }
        deleteCellFromList(list, list->heads->cells[0]);
    }
    for (int i = 0; i < list->heads->nbLevel; i++) {
        free(list->heads->cells[i]);
    }
    free(list->heads);
    free(list);
}

//création d'une List de hauteur n et de longueur 2^n - 1
List *createDichotomousList(int level) {
    List *dichoList = createList(level);
    for (int i = (int)pow(2, level) - 1; i >0; i--) {
        int j = level-1;
        while (j >= 0 && i % (int)pow(2, j) != 0) {
            j--;
        }
        Cell *newCell = createCell(j+1, i);
        insertCellInListFromHead(newCell, dichoList);
    }
    return dichoList;
}

//recherche d'une valeur sur un niveau à partir d'une List
Cell *searchAtOneLevelOfList(List *list, int value, int level) {
    if (list != NULL || level >= 0) {
        return searchValueAtOneLevel(list->heads->cells[level], value, level);
    } else {
        return NULL;
    }
}

// recherche d'une valeur sur un niveau
Cell *searchValueAtOneLevel(Cell *cell, int value, int level) {
    if (cell != NULL) {
        if (cell->value != value) {
            searchValueAtOneLevel(cell->next->cells[level], value, level);
        } else {
            return cell;
        }
    } else {
        return NULL;
    }
}

//recherche dichotomique à partir d'une List
Cell *searchDichotomouslyFromList(List *list, int value){
    if (list != NULL) {
        int level = (list->heads->nbLevel) - 1;
        return searchDichotomously(value, level, list, list->heads->cells[level]);
    } else {
        return NULL;
    }
}

Cell *searchDichotomously(int value, int level, List *list, Cell *comparison) {
    if (level < 0) {
        return NULL;
    } else {
        if (comparison->value == value) {
            return comparison;
        } else {
            if (level != 0) {
                if (comparison->value > value) {
                    Cell *previous = searchPrevious(list->heads->cells[level - 1], comparison->value, level - 1);
                    searchDichotomously(value, level - 1, list, previous);
                } else {
                    searchDichotomously(value, level - 1, list, comparison->next->cells[level-1]);
                }
            } else {
                return NULL;
            }
        }
    }
}

//recherche de la Cell précédente pour un niveau
Cell *searchPrevious(Cell *head, int value, int level) {
    Cell *tmp = head;
    Cell *previous = NULL;
    while (tmp->value != value) {
        previous = tmp;
        tmp = tmp->next->cells[level];
    }
    return previous;
}
