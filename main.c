#include "Cell.h"
#include "List.h"
#include "string.h"
int main() {
    List *list = createList(5);
    //displayListSimply(list);
    Cell *cell0 = createCell(5, 1);
    Cell *cell1 = createCell(5, 2);
    Cell *cell2 = createCell(5, 3);
    //Cell *cell3 = createCell(5, 4);
    //Cell *cell4 = createCell(3, 5);


    //cellsAddAt(cell0->next, cell1, 0);
    insertCellInListCresentlyByStr(cell0, list);
    insertCellInListCresentlyByStr(cell1, list);
    insertCellInListCresentlyByStr(cell2, list);
    //insertCellInListCresentlyByStr(cell3,list);
    //insertCellInListCresentlyByStr(cell4,list);
    displayListSimply(list);

    deleteCell(cell0);
    deleteCell(cell1);
    deleteCell(cell2);
    //deleteCell(cell3);
    //deleteCell(cell4);
   deleteList(list);

    /*char prenom[100];
    scanString(prenom);
    printf( "le nom finale est %s",prenom);
    printf("\n %d",prenom[0]);
    char prenom2[100];
    scanString(prenom2);
    printf("a<b = %d",prenom[0]>prenom2[0]);*/
    return 0;
}
