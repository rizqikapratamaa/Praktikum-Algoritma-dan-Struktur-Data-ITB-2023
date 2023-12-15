#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin Ln, Lm, LFinal;
    int n, m, i;

    scanf("%d", &n);
    CreateListDin(&Ln, n); NEFF(Ln) = n;

    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(Ln, i));
    }

    scanf("%d", &m);
    CreateListDin(&Lm, m); NEFF(Lm) = m;
    for (i = 0; i < m; i++){
        scanf("%d", &ELMT(Lm, i));
    }

    CreateListDin(&LFinal, n + m + 10);

    while (NEFF(Ln) !=0 && NEFF(Lm) != 0){
        if (ELMT(Ln, 0) >= ELMT(Lm, 0)){
            insertLast(&LFinal, ELMT(Ln, 0));

            int j;

            for (j = 0; j < getLastIdx(Ln); j++){
                ELMT(Ln, j) = ELMT(Ln, j + 1);
            }
            NEFF(Ln)--;
        } else {
            insertLast(&LFinal, ELMT(Lm, 0));

            int j;

            for (j = 0; j < getLastIdx(Lm); j++){
                ELMT(Lm, j) = ELMT(Lm, j + 1);
            }
            NEFF(Lm)--;
        }
    }

    if (NEFF(Ln) != 0){
        int j;

        for (j = 0; j <= getLastIdx(Ln); j++){
            insertLast(&LFinal, ELMT(Ln, j));
        }
    }

    if (NEFF(Lm) != 0){
        int j;

        for (j = 0; j <= getLastIdx(Lm); j++){
            insertLast(&LFinal, ELMT(Lm, j));
        }
    }
    printList(LFinal);
    printf("\n");
}