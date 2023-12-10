#include "Cell.h"
#include "List.h"
#include "timer.h"



int main() {
    List *list;
    Cell *cell;
    FILE *log_file = fopen("log100000.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    char *time_lvl0;
    char *time_all_levels;
    for (int i = 7; i <= 16; i++) {
        printf("niveau %d :\n", i);
        printf("Recherche classique :\n");
        list = createDichotomousList(i);
        startTimer();
        for (int j = 0; j < 100000; j++) {
            srand((unsigned int)time);
            int value = rand()%(int)pow(2, i);
            cell = searchAtOneLevelOfList(list, value, 0);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        displayTime();
        printf("\n");
        printf("Recherche dichotomique :\n");
        startTimer();
        for (int j = 0; j < 100000; j++) {
            srand((unsigned int)time);
            int value = rand()%(int)pow(2, i);
            cell = searchDichotomouslyFromList(list, value);
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();
        fprintf(log_file,format,i,time_lvl0, time_all_levels);
        printf("\n\n");
        deleteList(list);
    }
    fclose(log_file);
    return 0;
}
