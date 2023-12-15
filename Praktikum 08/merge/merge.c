#include <stdio.h>
#include "listlinier.h"
#include "merge.h"
#include "boolean.h"

void splitList(List source, List* front, List* back) {
    int len = length(source);
    int frontBound = (len % 2) ? (len / 2) : ((len / 2) - 1);

    List p = source;
    int i;
    for (i = 0; i < len; i++) {
        if (i <= frontBound) {
            insertLast(front, INFO(p));
        } else {
            insertLast(back, INFO(p));
        }
        p = NEXT(p);
    }
}

List merge(List a, List b) {
    List res;
    CreateList(&res);

    if (a == NULL) return b;
    else if (b == NULL) return a;
    else {
        List tempA = a;
        List tempB = b;
        ElType val;

        // Loop until tempA is empty or tempB is empty
        while ((tempA != NULL) && (tempB != NULL)) {
            if (INFO(tempA) <= INFO(tempB)) 
                deleteFirst(&tempA, &val);
            else 
                deleteFirst(&tempB, &val);
            
            insertLast(&res, val);
        }

        // Empty TempA
        while (tempA != NULL) {
            deleteFirst(&tempA, &val);
            insertLast(&res, val);
        }

        // Empty TempB
        while (tempB != NULL) {
            deleteFirst(&tempB, &val);
            insertLast(&res, val);
        }

        return res;
    }
}

void mergeSort(List* list) {
    displayList(*list); printf("\n");
    if (length(*list) > 1) {
        
        List front; CreateList(&front);
        List back; CreateList(&back);

        splitList(*list, &front, &back);
        mergeSort(&front);
        mergeSort(&back);

        List merged = merge(front, back);
        *list = merged;
    }
}