//
// Created by lucbe on 26/10/2023.
//

#include "List.h"
List* createList(int maxLevel){
    List *newList=(List*) malloc(sizeof (List));
    newList->heads= createCells(maxLevel);
    return newList;
}
