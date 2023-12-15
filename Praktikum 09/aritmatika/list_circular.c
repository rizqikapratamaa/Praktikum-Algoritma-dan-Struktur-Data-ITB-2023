#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

Address allocate(ElType val){
    Address p = (Address) malloc (sizeof(ElmtList));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P){
    free(P);
}

Address search(List l, ElType val){
    if(isEmpty(l)){
        return NULL;
    }
    Address p = FIRST(l);
    while(NEXT(p) != FIRST(l) && INFO(p) != val){
        p = NEXT(p);
    }
    if(INFO(p) == val){
        return p;
    }
    return NULL;
}

boolean addrSearch(List l, Address p){
    if(isEmpty(l)){
        return false;
    }
    Address q = FIRST(l);
    while(NEXT(q) != FIRST(l) && q != p){
        q = NEXT(q);
    }
    return q == p;
}

void insertFirst(List *l, ElType val){
    Address p = allocate(val);
    if(p != val){
        if(isEmpty(*l)){
            NEXT(p) = p;
        }
        else{
            Address q = FIRST(*l);
            while(NEXT(q) != FIRST(*l)){
                q = NEXT(q);
            }
            NEXT(p) = FIRST(*l);
            NEXT(q) = p;
        }
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val){
    Address p = allocate(val);
    if( p != NULL){
        if(isEmpty(*l)){
            insertFirst(l, val);
        }
        else{
            Address q = FIRST(*l);
            while(NEXT(q) != FIRST(*l)){
                q = NEXT(q);
            }
            NEXT(q) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l), q = FIRST(*l);
    *val = INFO(p);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    }
    else{
        while(NEXT(q) != FIRST(*l)){
            q = NEXT(q);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(q) = FIRST(*l);
    }
    free(p);
}

void deleteLast(List *l, ElType *val){
    Address p = FIRST(*l), q = NULL;
    while(NEXT(p) != FIRST(*l)){
        q = p;
        p = NEXT(p);
    }
    if(q == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(q) = FIRST(*l);
    }
    *val = INFO(p);
    free(p);
}

void displayList(List l){
    printf("[");
    if(!isEmpty(l)){
        Address p = FIRST(l);
        printf("%d", INFO(p));
        p = NEXT(p);
        while(p != FIRST(l)){
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
    }
    printf("]");
}