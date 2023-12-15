#include <stdio.h>
#include <stdlib.h>

int main (){
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int i = 1;
    for(i; i <= m; i++){
        if (i % n == 0){
            printf("happy\n");
        }
        else{
            printf("%d\n", i);
        }
    }
    return 0;
}