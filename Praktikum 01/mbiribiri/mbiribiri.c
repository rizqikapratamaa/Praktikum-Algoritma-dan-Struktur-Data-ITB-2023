#include "point.h"
#include "garis.h"
#include <stdio.h>

int main(){
    float b;
    POINT P1, P2;
    GARIS L;
    int n, i, count = 0;
    scanf("%f", &b);
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    CreateGaris(&L, P1, P2);
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        BacaPOINT(&P1);
        if(JarakGARIS(L, P1) <= b){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}