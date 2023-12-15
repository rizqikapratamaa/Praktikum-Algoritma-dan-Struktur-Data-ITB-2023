#include <stdio.h>
#include "stack.h"

void SortirKeranjang (Stack * S1, Stack * S2) {
    int i, j, value[100], temp, isi1 = Top(*S1) + 1;
    for (i = 0; i < isi1; i++) {
        Pop(S1, &temp);
        value[i] = temp;
    }

    for (i = 0; i < isi1; i++) {
        for (j = 0; j < isi1 - 1; j++ ) {
            if (value[j+1] > value[j]) {
                temp = value[j];
                value[j] = value[j+1];
                value[j+1] = temp;
            }
        }
    }

    for (i = 0; i < isi1; i++) {
        Push(S2, value[i]);
    }
}