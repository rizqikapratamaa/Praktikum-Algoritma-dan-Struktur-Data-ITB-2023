#include <stdio.h>
#include "list_circular.h"

int main(){
    int n; scanf("%d", &n);

    List l;
    CreateList(&l);

    int i;
    for(i = 1; i<=n; i++){
        insertLast(&l, i);
    }

    for(i = 1; i < n; i++){
        int a; scanf("%d", &a);

        Address head = FIRST(l);

        if ( a < 0){
            a *= -1;
            int j;
            for(j = 1; j <= a; j++){
                Address tail = head;

                while (NEXT(tail) != head)
                {
                    tail = NEXT(tail);
                }
                
                head = tail;

                if (i != 1 && j == 1){
                    int temp;
                    deleteFirst(&l, &temp);
                }
            }
        } else {
            int j;
            for(j = 1; j <= a; j++){
                head = NEXT(head);

                if (i != 1 && j == 1){
                    int temp;
                    deleteFirst(&l, &temp);
                }
            }

            
        }

        FIRST(l) = head;
    }

    int temp;
    deleteFirst(&l, &temp);

    printf("%d\n", INFO(FIRST(l)));
}