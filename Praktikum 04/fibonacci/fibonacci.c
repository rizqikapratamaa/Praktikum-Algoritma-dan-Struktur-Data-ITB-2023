#include <stdio.h>
#include "matrix.h"

Matrix identityMatrix2x2() {
    Matrix m;
    createMatrix(2, 2, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 0, 1) = 0;
    ELMT(m, 1, 0) = 0;
    ELMT(m, 1, 1) = 1;
    return m;
}

Matrix PangkatMatrix(Matrix m, long long int pangkat) {
    if (pangkat == 0) return identityMatrix2x2();
    else if (pangkat == 1) return m;
    else {
        Matrix m2 = PangkatMatrix(m, pangkat / 2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2, m2, 2003);
        if (pangkat % 2 == 1) {
            mulMatrix = multiplyMatrixWithMod(mulMatrix, m, 2003);
        }
        return mulMatrix;
    }
}

int main() {
    long long int K;
    scanf("%lld", &K);

    Matrix m;
    createMatrix(2, 2, &m);
    ELMT(m, 0, 0) = 1;
    ELMT(m, 0, 1) = 1;
    ELMT(m, 1, 0) = 1;
    ELMT(m, 1, 1) = 0;

    Matrix result = PangkatMatrix(m, K - 1);
    printf("%d\n", ELMT(result, 0, 0));

    return 0;
}
