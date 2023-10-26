//
// Created by lucbe on 26/10/2023.
//

#include "Cell.h"
#include "Cells.h"

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

typedef struct List {
    Cells heads;
} List;

List *createList(int height);

#endif //PROJECT_LIST_H
