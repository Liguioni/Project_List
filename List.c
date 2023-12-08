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
void insertCellInListFromHead(Cell *cell, List *list) {
    for (int i = 0; i < cell->next->nbLevel; i++) {
        if (cell->next->nbLevel <= list->heads->nbLevel) {
        cell->next->cells[i] = list->heads->cells[i];
        list->heads->cells[i] = cell;
        }
    }
}

void insertCellInListCresently(Cell *cell,List*list){
    if((list->heads->cells[0]==NULL)||(cell->value<list->heads->cells[0]->value)){
        insertCellInListFromHead(cell,list);
        return;
    }
    Cell *temp=list->heads->cells[0];
    while((temp->next->cells[0]!=NULL)&&(cell->value > temp->next->cells[0]->value)){

        temp=temp->next->cells[0];

    }
    for(int i=0;i<cell->next->nbLevel;i++){

        cell->next->cells[i]=temp->next->cells[i];
        temp->next->cells[i]=cell;
    }
}
void insertCellInListCresentlyByStr(Cell *cell,List*list){
    //Cell* tempListcomp=list->heads->cells[0];
    if((list->heads->cells[0]==NULL)||(cell->nom_prenom[0]<list->heads->cells[0]->nom_prenom[0])) {
        insertCellInListFromHead(cell, list);
        printf("ajout en tete \n ");
        return;
    }
    Cell *temp=list->heads->cells[0];
    int control=0;
    if(cell->nom_prenom[0]!=temp->nom_prenom[0]){
        while((temp->next->cells[0]!=NULL)&&(cell->nom_prenom[0]>temp->next->cells[0]->nom_prenom[0])){
            temp=temp->next->cells[0];
        }
        control=3;
    }else if((cell->nom_prenom[1]!=temp->nom_prenom[1])/*&&(cell->nom_prenom[0]==temp->nom_prenom[0])*/){
        control=2;
        while((temp->next->cells[0]!=NULL)&&(cell->nom_prenom[1]>temp->nom_prenom[1])){
            temp=temp->next->cells[0];
        }
    }else if((cell->nom_prenom[2]!=temp->nom_prenom[2])&&(cell->nom_prenom[1]==temp->nom_prenom[1])&&(cell->nom_prenom[0]==temp->nom_prenom[0])){
        control=1;
            while((temp->next->cells[0]!=NULL)&&(cell->nom_prenom[2]>temp->next->cells[0]->nom_prenom[2])){
                temp=temp->next->cells[0];
            }
    }
    cell->next->cells[0]=temp->next->cells[0];
    temp->next->cells[0]=cell;
    cell->next->cells[control]=temp->next->cells[control];
    temp->next->cells[control]=cell;



}

// affichage d'un niveau de la List simplement
void displayOneLevelOfListSimply(List *list, int level) {
    if (level >= 0 && level < list->heads->nbLevel) {
        printf("[list head_%d @-]", level);
        Cell *cell = list->heads->cells[level];
        while (cell != NULL) {
            printf("-->[ %s|@-]", cell->nom_prenom);
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