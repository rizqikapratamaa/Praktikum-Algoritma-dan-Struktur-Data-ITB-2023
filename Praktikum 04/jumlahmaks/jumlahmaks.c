#include <stdio.h>
#include "matrix.h"

int main() {
    int N, M, K;
    Matrix m;
    scanf("%d %d %d", &N, &M, &K);
    readMatrix(&m, N, M);

    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = i; k < N; k++) {
                for (int l = j; l < M; l++) {
                    int area = (k - i + 1) * (l - j + 1);
                    if (area == K) {
                        int sum = 0;
                        for (int x = i; x <= k; x++) {
                            for (int y = j; y <= l; y++) {
                                sum += ELMT(m, x, y);
                            }
                        }
                        if (sum > maxSum) {
                            maxSum = sum;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", maxSum);
    return 0;
}
