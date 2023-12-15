#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix m;
    createMatrix(8, 8, &m);
    readMatrix(&m, 8, 8);
    int i, j;
    int hitam = 0, putih = 0;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (i % 2 != 0){
                if(j % 2 != 0){
                    if (ELMT(m, i, j) == 1){
                        hitam++;
                    }
                }
                if (j % 2 == 0){
                    if (ELMT(m, i, j) == 1){
                        putih++;
                    }
                }
            }
            if (i % 2 == 0){
                if (j % 2 != 0){
                    if (ELMT(m , i, j) == 1){
                        putih++;
                    }
                }
                if (j % 2 == 0){
                    if (ELMT(m,i, j) == 1){
                        hitam++;
                    }
                }
            }
        }
    }
    printf("%d %d", hitam, putih); printf("\n");
    return 0;
}