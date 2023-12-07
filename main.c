#include "Cell.h"
#include "List.h"
#include "timer.h"



int main() {
    List *list;
    Cell *cell;
    for (int i = 1; i <= 50; i++) {
        list = createDichotomousList(i);
        int value = 5558889;
        startTimer();
        cell = searchDichotomouslyFromList(list, value);
        displayTime();
        stopTimer();
        if (i < 16) {
            startTimer();
            cell = searchAtOneLevelOfList(list, value, 0);
            displayTime();
            stopTimer();
        }
        printf("puissance %d\n", i);
        if (cell != NULL) {
            printf("%d : Cell presente\n", value);
        } else {
            printf("%d : Cell introuvable\n", value);
        }
        printf("\n\n");
        deleteList(list);
    }
    return 0;
}
