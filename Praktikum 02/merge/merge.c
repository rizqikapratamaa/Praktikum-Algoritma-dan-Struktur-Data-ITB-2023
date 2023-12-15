#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l1;
    CreateListStatik(&l1);
    readList(&l1);

    ListStatik l2;
    CreateListStatik(&l2);
    readList(&l2);
    int i;
    for (i = IDX_MIN; i < listLength(l2); i++){
        insertLast(&l1, ELMT(l2, i));
    }
    sortList(&l1, true);
    printList(l1); printf("\n");
    return 0;
}