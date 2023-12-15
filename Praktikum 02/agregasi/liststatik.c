#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
    int i;
    for(i=0;i<CAPACITY;i++){
        ELMT(*l,i)=MARK;
    }
}

int listLength(ListStatik l){
    int i=0;
    while(i<CAPACITY && ELMT(l,i)!=MARK){
        i++;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l){
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    return listLength(l)-1;
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (IDX_MIN<=i && i<CAPACITY);
}

boolean isIdxEff(ListStatik l, IdxType i){
    return (IDX_MIN<=i && i<=(listLength(l)-1));
}

boolean isEmpty(ListStatik l){
    return ELMT(l,IDX_MIN)==MARK;
}

boolean isFull(ListStatik l){
    return !(ELMT(l,CAPACITY-1)==MARK);
}

void readList(ListStatik *l){
    CreateListStatik(l);
    int n,i;

    do{
    scanf("%d",&n);
    } while(n<0 || n>CAPACITY);

    for(i=0;i<n;i++){
        scanf("%d",&ELMT(*l,i));
    }
}

void printList(ListStatik l){
    printf("[");

    int i;for(i=0;i<listLength(l);i++){
        printf("%d",ELMT(l,i));
        if(i!=getLastIdx(l))printf(",");
    }

    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l3;
    CreateListStatik(&l3);
    IdxType i;
    for (i = IDX_MIN; i <= listLength(l1)-1; i++) {
        if (plus) {
            ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
        }
        else {
            ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l3;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    boolean found = true;
    if (listLength(l1) != listLength(l2)) {
        found = false;
    }
    else {
        IdxType i;
        for (i = IDX_MIN; i <= listLength(l1)-1; i++) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                found = false;
            }
        }
    }
    return found;
}

int indexOf(ListStatik l,ElType val){
    IdxType i;
    if(listLength(l)==0)i=IDX_UNDEF;
    else{
        i=0;
        while(ELMT(l,i)!=val&&i<listLength(l)){
            i++;
        }
        if(i==listLength(l))i=IDX_UNDEF;
    }
    return i;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l,0);
    *min = ELMT(l,0);

    int i;
    for(i=1;i<listLength(l);i++){
        if(*max<ELMT(l,i)){
            *max = ELMT(l,i);
        }
        if(*min>ELMT(l,i)){
            *min = ELMT(l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    IdxType i;
    for (i = listLength(*l)-1; i >= IDX_MIN; i--) {
        ELMT(*l,i+1) = ELMT(*l,i);
    }
    ELMT(*l,getFirstIdx(*l)) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    IdxType i;
    for (i = listLength(*l)-1; i >= idx; i--) {
        ELMT(*l,i+1) = ELMT(*l,i);
    } 
    ELMT(*l,idx) = val; 
}

void insertLast(ListStatik *l, ElType val){
    if (!isEmpty(*l)) {
        ELMT(*l,getLastIdx(*l)+1) = val;
    }
    else {
        ELMT(*l,IDX_MIN) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val){
    IdxType i;
    *val = ELMT(*l,getFirstIdx(*l));
    for (i = IDX_MIN; i <= listLength(*l)-1; i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    IdxType i;
    *val = ELMT(*l,idx);
    for (i = idx; i <= listLength(*l)-1; i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l,getLastIdx(*l));
    ELMT(*l,getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
    IdxType i, j;
    ElType temp;
    int n = listLength(*l);

    for (i = getFirstIdx(*l); i <= getLastIdx(*l) - 1; i++) {
        for (j = i + 1; j <= getLastIdx(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}
