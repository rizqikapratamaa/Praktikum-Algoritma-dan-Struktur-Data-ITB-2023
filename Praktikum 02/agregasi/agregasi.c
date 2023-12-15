#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main() {
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);
    int x;
    scanf("%d", &x);
    sortList(&l, true);
    printList(l);
    printf("\n");

    int length = listLength(l);

    if (indexOf(l, x) == IDX_UNDEF) {
        float sum = 0, ave = 0;
        int j;
        for (j = IDX_MIN; j < length; j++) {
            sum += ELMT(l, j);
        }
        if (length > 0) {
            ave = sum / length;
        }
        printf("Average: %.2f\n", ave);
        printf("%d tidak ada\n", x);
    } else {
        float sum = 0, ave = 0;
        int j;
        for (j = IDX_MIN; j < length; j++) {
            sum += ELMT(l, j);
        }
        if (length > 0) {
            ave = sum / length;
        }
        printf("Average: %.2f\n", ave);
        int index = indexOf(l, x);
        printf("%d\n", index);
        
        int max = ELMT(l, getLastIdx(l));
        int min = ELMT(l, getFirstIdx(l));
        int mid;
        if (length % 2) {
            mid = ELMT(l, length / 2);
        } else {
            mid = ELMT(l, length / 2 - 1);
        }

        if (x == max) printf("X maksimum\n");
        if (x == min) printf("X minimum\n");
        if (x == mid) printf("X median\n");
    }

    return 0;
}