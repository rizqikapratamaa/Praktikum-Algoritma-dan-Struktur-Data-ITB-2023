#include <stdio.h>
#include <math.h>
#include "listdin.h"


int main(){
    ListDin L;
    CreateListDin(&L,0);

    int n; scanf("%d", &n);

    while (n > 0){
        int tipe;

        scanf("%d",&tipe);

        if(tipe==1){
            int x;
            scanf("%d",&x);

            if (CAPACITY(L) == 0){
                expandList(&L, 1);
            } else if (isFull(L)){
                expandList(&L, CAPACITY(L));
            }

            insertLast(&L, x);

        }else if(tipe==2){
            int temp;
            deleteLast(&L, &temp);

            if (NEFF(L) <= round(CAPACITY(L)/2)){
                CAPACITY(L) = round(CAPACITY(L)/2);
            }

        }else{
            printf("%d ", CAPACITY(L));
            printList(L);
            printf("\n");
        }
        n--;
    }
}