#include "Cell.h"
#include "List.h"
#include "string.h"
#include "Meeting.h"
int main() {
    List *list = createList(4);
    //displayListSimply(list);
    Cell *cell0 = createCell(4, 1);
    Cell *cell1 = createCell(4, 2);
    Cell *cell2 = createCell(4, 3);
    Cell *cell3 = createCell(4, 4);
    //Cell *cell4 = createCell(3, 5);


    //cellsAddAt(cell0->next, cell1, 0);
    insertCellInListCresentlyByStr(cell0, list);
    insertCellInListCresentlyByStr(cell1, list);
    insertCellInListCresentlyByStr(cell2, list);
    insertCellInListCresentlyByStr(cell3,list);
    //insertCellInListCresentlyByStr(cell4,list);
    displayListSimply(list);

    deleteCell(cell0);
    deleteCell(cell1);
    deleteCell(cell2);
    deleteCell(cell3);
    //deleteCell(cell4);
    deleteList(list);





    return 0;
}
