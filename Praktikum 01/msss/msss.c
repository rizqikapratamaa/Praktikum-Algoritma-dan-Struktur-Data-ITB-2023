#include <stdio.h>
#include <math.h>
#include "point.h"

int main(){
    POINT P1, P2, P3;

    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);

    float 
    SelisihY32 = Ordinat(P3) - Ordinat(P2),
    SelisihY21 = Ordinat(P2) - Ordinat(P1),
    SelisihB32 = Absis(P3) - Absis(P2),
    SelisihB21 = Absis(P2) - Absis(P1),
    SelisihC32 = pow(Absis(P3), 2) - pow(Absis(P2), 2),
    SelisihC21 = pow(Absis(P2), 2) - pow(Absis(P1), 2);

    float divider = SelisihB32/SelisihB21;

    float
    EliminasiC = SelisihC21*divider,
    EliminasiY = SelisihY21*divider;

    float
    C = (SelisihY32 - EliminasiY)/(SelisihC32 - EliminasiC),
    B = (SelisihY32 - C * SelisihC32)/SelisihB32,
    A = Ordinat(P1) - (B * Absis(P1)) - (C * pow(Absis(P1), 2));

    printf("%.0f\n", A);
    return 0;
}

