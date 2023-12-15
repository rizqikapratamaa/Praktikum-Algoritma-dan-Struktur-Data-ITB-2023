#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin L;
    int capacity; scanf("%d", &capacity);
    CreateListDin(&L, capacity);

    int i; scanf("%d", &i);

    while (i > 0){
        int queryNum; scanf("%d", &queryNum);

        if (queryNum == 1){
            int val; scanf("%d", &val);

            insertLast(&L, val);

            int j, temp;
            for (j = 0; j <= getLastIdx(L); j++){
                if (ELMT(L, j) < val){
                    int k;

                    for (k = j; k <= getLastIdx(L) - 1; k++){
                        ELMT(L, k) = ELMT(L, k+1);
                    }

                    NEFF(L)--;
                    j--;
                }
            }
        } else {
            printf("%d\n", NEFF(L));
            printList(L);
            printf("\n");
        } 
        i--;
    }
}