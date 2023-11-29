#include "Cell.h"
#include "List.h"



int main() {
    List *list = createDichotomousList(3);
    displayListSimply(list);
    Cell *cell = searchDichotomouslyFromList(list, 8);
    if (cell != NULL) {
        printf("Cell presente\n");
    } else {
        printf("Cell introuvable\n");
    }
    return 0;
}
