#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin A;
    int N;
    scanf("%d", &N);

    CreateListDin(&A, N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &ELMT(A, i));
    }

    if (N == 1) {
        printf("0\n");
    } else {
        ElType maxVal = ELMT(A, 0);
        ElType minVal = ELMT(A, 0);

        for (int i = 0; i < N; i++) {
            if (ELMT(A, i) > maxVal) {
                maxVal = ELMT(A, i);
            }
            if (ELMT(A, i) < minVal) {
                minVal = ELMT(A, i);
            }
        }

        ElType maxDiff = maxVal - minVal;

        for (int i = 0; i < N; i++) {
            ElType temp = ELMT(A, i) + 1;
            if (temp > maxVal) {
                maxVal = temp;
            }
            if (temp < minVal) {
                minVal = temp;
            }

            ElType newDiff = maxVal - minVal;

            if (newDiff > maxDiff) {
                maxDiff = newDiff;
            }
        }

        printf("%d\n", maxDiff);
    }

    dealocateList(&A);

    return 0;
}
