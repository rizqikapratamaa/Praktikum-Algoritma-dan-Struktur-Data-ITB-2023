#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int input;
    int sum = 0;
    scanf("%d", &input);
    while (input > 0){
        int lastDigit = input % 10;
        sum = sum + lastDigit;
        input = input / 10;
    }
    printf("%d\n", sum);
    return 0;
}
