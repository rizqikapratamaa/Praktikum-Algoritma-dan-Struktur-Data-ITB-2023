#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"

Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack s){
    return ADDR_TOP(s) == NULL;
}

int length(Stack s){
    Address p = ADDR_TOP(s);
    int res = 0;
    while(p != NULL){
        res++;
        p = NEXT(p);
    }
    return res;
}

void CreateStack(Stack *s){
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s){
    Address p = ADDR_TOP(s);
    int i;
    printf("[");
    for(i = 0; i < length(s); i++){
        printf("%d", INFO(p));
        p = NEXT(p);
        if(i != length(s)-1){
            printf(",");
        }
    }
    printf("]");
}

void push(Stack *s, ElType x){
    Address p = newNode(x);
    if(p != NULL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x){
    Address p = ADDR_TOP(*s);
    *x = INFO(p);
    ADDR_TOP(*s) = NEXT(p);
    free(p);
}