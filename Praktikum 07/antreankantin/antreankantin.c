#include <stdio.h>
#include "queue.h"

int main(){
    Queue q;
    CreateQueue(&q);

    boolean running = true;
    int input, waktu;
    int waktutotal = 0;
    int sum = 0;
    while (running){
        scanf("%d", &input);
        if (input == 1){
            scanf("%d", &waktu);
            if(!isFull(q)){
                enqueue(&q, waktu);
            }
            else{
                printf("Queue penuh\n");
            }
        }
        else if (input == 2){
            if(!isEmpty(q)){
                dequeue(&q, &waktu);
                waktutotal += waktu;
                sum++;
            }
            else{
                printf("Queue kosong\n");
            }
        }
        else{
            running = false;
        }
    }

    printf("%d\n", sum);

    if (sum == 0){
        printf("Tidak bisa dihitung\n");
    }
    else{
        printf("%.2f\n", ((float) waktutotal) / ((float) sum));
    }

}