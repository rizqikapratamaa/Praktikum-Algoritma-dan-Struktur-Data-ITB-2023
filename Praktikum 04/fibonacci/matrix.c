#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j){
    return (i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m){
    return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m){
    return (COL_EFF(m) - 1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    *mOut = mIn;
}

void readMatrix(Matrix *m, int nRow, int nCol){
    int i, j;
    ElType elm;
    createMatrix(nRow, nCol, m);
    for (i = 0; i < nRow; i++){
        for (j = 0; j < nCol; j++){
            scanf("%d", &elm);
            ELMT(*m, i, j) = elm;
        }
    }
}
void displayMatrix(Matrix m){
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1){
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1){
            printf("\n");
        }
    }
    printf("\n");
}

Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++){
                ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod){
    Matrix m3;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(m3, i, j) %= mod;
        }
    }
    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x){
    Matrix m3;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m3;
}
void pMultiplyByConst(Matrix *m, ElType k){
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (countElmt(m1) == countElmt(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)){
        for (int i = 0; i < ROW_EFF(m1); i++){
            for (int j = 0; j < COL_EFF(m1); j++){
                if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !isMatrixEqual(m1, m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2)) && ((COL_EFF(m1) == COL_EFF(m2)));
}

int countElmt(Matrix m){
    return (ROW_EFF(m) * COL_EFF(m));
}

boolean isSquare(Matrix m){
    return ROW_EFF(m) == COL_EFF(m);
}
boolean isSymmetric(Matrix m){
    boolean sym = true;
    int i, j;
    i = 0;
    j = 0;
    if (isSquare(m) == true){
        while ((i < ROW_EFF(m)) && (sym != false)){
            while ((j < COL_EFF(m)) && (sym != false)){
                if (ELMT(m, i, j) != ELMT(m, j, i)){
                    sym = false;
                }
                j++;
            }
            i++;
        }
    }
    else{
        sym = false;
    }

    return sym;
}
boolean isIdentity(Matrix m)
{
    boolean id = true;
    int i, j;
    i = 0;
    j = 0;
    if (isSquare(m) == true){
        while ((i < ROW_EFF(m)) && (id != false)){
            while ((j < COL_EFF(m)) && (id != false)){
                if (i == j){
                    if (ELMT(m, i, j) != 1){
                        id = false;
                    }
                }
                else{
                    if (ELMT(m, i, j) != 0){
                        id = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
    else{
        id = false;
    }
    return id;
}
boolean isSparse(Matrix m){
    float max = (ROW_EFF(m) * COL_EFF(m)) * 0.05;
    max = (int)max;
    int countNotZero = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (ELMT(m, i, j) != 0){
                countNotZero++;
            }
        }
    }
    return (countNotZero <= max);
}
Matrix negation(Matrix m){
    Matrix m3;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
    for (i = 0; i < ROW_EFF(m3); i++){
        for (j = 0; j < COL_EFF(m3); j++){
            ELMT(m3, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return m3;
}
void pNegation(Matrix *m){
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * (-1);
        }
    }
}

float determinant(Matrix m){
    if (ROW_EFF(m) == 1){
        return ELMT(m, 0, 0);
    }
    float det = 0.0;
    int sign = 1;
    for (int j = 0; j < COL_EFF(m); j++){
        if (ELMT(m, 0, j) != 0){
            Matrix subMatrix;
            createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &subMatrix);
            int sub_i = 0;
            for (int i = 1; i < ROW_EFF(m); i++){
                int sub_j = 0;
                for (int k = 0; k < COL_EFF(m); k++){
                    if (k != j){
                        ELMT(subMatrix, sub_i, sub_j) = ELMT(m, i, k);
                        sub_j++;
                    }
                }
                sub_i++;
            }
            det += (sign * ELMT(m, 0, j) * determinant(subMatrix));
        }
        sign = -sign;
    }
    return det;
}

Matrix transpose(Matrix m){
    Matrix mhasil;
    int i, j;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(mhasil, j, i) = ELMT(m, i, j);
        }
    }
    return mhasil;
}

void pTranspose(Matrix *m){
    Matrix mhasil;
    int i, j;
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &mhasil);
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMT(mhasil, j, i) = ELMT(*m, i, j);
        }
    }
    *m = mhasil;
}