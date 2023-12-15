#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int fibonacci(int n){
    printf("fibonacci(%d)\n",n);
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return  1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
}

int main(){
    int n;
    Stack S1;
    CreateEmpty(&S1);
    scanf("%d",&n);
    int result = fibonacci(n);
    printf("%d\n",result);
    return 0;
}