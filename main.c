#include "Cell.h"
#include "List.h"

int main() {
    List *list = createList(5);
    displayListSimply(list);
    Cell *cell0 = createCell(5, 1);
    Cell *cell1 = createCell(5, 2);
    cellsAddAt(cell0->next, cell1, 0);
    insertCellInListFromHead(cell0, list);
    displayListSimply(list);
    deleteCell(cell0);
    deleteCell(cell1);
    deleteList(list);
    return 0;
}
