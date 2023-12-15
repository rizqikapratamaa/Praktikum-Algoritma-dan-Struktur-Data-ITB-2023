#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main() {
    ListStatik l1, l2, hasil;
    int n1 = 0;
    int n2 = 0;

    int result;

    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&hasil);

    readList(&l1);
    readList(&l2);

    for (int i = 0; i <= getLastIdx(l1); i++){
        n1 = n1 * 10 + ELMT(l1, i);
    }
    for (int i = 0; i <= getLastIdx(l2); i++){
        n2 = n2 * 10 + ELMT(l2, i);
    }

    result = n1 + n2;

    int temp = result;
    int length = 0;
    if (temp == 0){
        length = 1;
    }
    else{
        while (temp != 0){
            temp /= 10;
            length++;
        }
    }
    
    CreateListStatik(&hasil);
    for(int k = length - 1; k >= 0; k--){
        ELMT(hasil, k) = result % 10;
        result /= 10;
    }

    printList(hasil);
    printf("\n");

    return 0;
}
