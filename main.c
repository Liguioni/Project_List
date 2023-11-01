#include "Cell.h"
#include "List.h"

int main() {
    List *list = createList(5);
    displayListSimply(list);
    Cell *cell0 = createCell(5, 1);
    insertCellInList(cell0, list);
    displayListSimply(list);
    deleteList(list);
    return 0;
}
