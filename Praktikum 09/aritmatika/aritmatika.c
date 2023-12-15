#include <stdio.h>
#include "list_circular.h"

int main(){
    int N, i;
    ElType val;
    List l;
    CreateList(&l);

    scanf("%d", &N);

    for (i = 0; i < N; i++){
        scanf("%d", &val);
        insertLast(&l, val);
    }

    int b = INFO(FIRST(l));
    int selisih = INFO(NEXT(FIRST(l))) - b;
    
    Address p = FIRST(l);
    int j = 0;
    boolean beda = false;
    int dump = INFO(NEXT(p)) - INFO(p);
    while(j < N-1){
        if(INFO(NEXT(p)) - INFO(p) == selisih){
            p = NEXT(p);
            j++;
        }
        else{
            beda = true;
            j++;
        }
    }
    if(!beda){
        printf("%d %d\n", selisih, b);
    }
    else{
        printf("0 0\n");
    }

    return 0;


}