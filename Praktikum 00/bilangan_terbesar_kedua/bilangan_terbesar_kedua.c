#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    scanf("%d", &n);

    int largest, secondLargest;
    scanf("%d", &largest);
    scanf("%d", &secondLargest);

    if(secondLargest > largest){
        int temp = largest;
        largest = secondLargest;
        secondLargest = temp;
    }

    int i = 2;
    for(i; i < n; i++){
        int num;
        scanf("%d", &num);

        if (num > largest){
            secondLargest = largest;
            largest = num;
        }else if (num > secondLargest && num != largest){
            secondLargest = num;
        }
    }
    printf("%d\n", secondLargest);
    return 0;
}