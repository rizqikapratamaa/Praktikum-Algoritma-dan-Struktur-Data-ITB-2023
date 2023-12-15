#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    for(int i = 0; i < a; i++){
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }
    
    for (int j = 0; j < b-j; j++){
        int temp = q.buffer[j];
        q.buffer[j] = q.buffer[b-j-1];
        q.buffer[b-j-1] = temp;
    }

    displayQueue(q);
}