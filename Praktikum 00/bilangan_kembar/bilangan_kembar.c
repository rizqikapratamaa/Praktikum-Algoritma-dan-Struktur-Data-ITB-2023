#include <stdio.h>

int main(){
    int a, b;
    int count = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    int i = a;
    for(i; i <= b; i++){
        int isKembar = 1;
        int n = i;
        int digitPertama = n % 10;
        n /= 10;
        while (n > 0){
            if (n % 10 != digitPertama){
                isKembar = 0;
                break;
            }
            n /= 10;
        }
        if (isKembar){
            count += 1;
        }
    }
    printf("%d\n", count);

    return 0;
}
