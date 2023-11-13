#include "graph.h"
#include <stdio.h>

void createEmptyGraf(Graf *g) {
    IdxGraf i, j;
    for (i = 0; i < ROW_GRAF; i++) {
        for (j = 0; j < COL_GRAF; j++) {
            ELMTGRAF(*g, i, j) = MARKGRAF;
        }
    }
}

void CreateListGraf(ListGraf *l) {
    IdxlistGraf i;
    for (i = 0; i < CAPACITYGRAF; i++) {
        ELMTLISTGRAF(*l, i) = MARKLISTGRAF;
    }
}

int listEffGraf(ListGraf l) {
    int count = 0;
    IdxlistGraf i = 0;
    while (ELMTLISTGRAF(l, i) != MARKLISTGRAF) {
        count++;
        i++;
    }
    return count;
}

boolean isEmptylistGraf(ListGraf l) {
    return listEffGraf(l) == 0;
}

void getOne(Graf g, IdxGraf rowID, ListGraf *l) {
    IdxGraf j;
    CreateListGraf(l);
    for (j = 0; j < COL_GRAF; j++) {
        if (ELMTGRAF(g, rowID, j) != MARKGRAF) {
            ELMTLISTGRAF(*l, listEffGraf(*l)) = ELMTGRAF(g, rowID, j);
        }
    }
}

void displayGraf(Graf g, int count) {
    IdxGraf i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < COL_GRAF; j++) {
            printf("%d ", ELMTGRAF(g, i, j));
        }
        printf("\n");
    }
}
