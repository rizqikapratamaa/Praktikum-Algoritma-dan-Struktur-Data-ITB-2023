#include "stacklinked.h"
#include <stdio.h>

int main() {
    Stack s1, s2, s3;
    int i, temp, n, Si, Di;
    CreateStack(&s1);   
    CreateStack(&s2);
    CreateStack(&s3);
    for (i = 5; i > 0; i--) {
        push(&s1, i);
    }      
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &Si, &Di);
        if (Si == 1) {
            if (isEmpty(s1)) {
                printf("Menara kosong\n");
            }
            else {
                pop(&s1, &temp);
                if (Di == 2) {
                    if (isEmpty(s2)) {
                        push(&s2, temp);
                    }
                    else if (TOP(s2) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s1, temp);
                    }
                    else {
                        push(&s2, temp);
                    }
                }
                else {
                    if (isEmpty(s3)) {
                        push(&s3, temp);
                    }                    
                    else if (TOP(s3) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s1, temp);
                    }
                    else {
                        push(&s3, temp);
                    }                    
                }
            }
        }
        else if (Si == 2) {
            if (isEmpty(s2)) {
                printf("Menara kosong\n");
            }
            else {
                pop(&s2, &temp);
                if (Di == 1) {
                    if (isEmpty(s1)) {
                        push(&s1, temp);
                    }                    
                    else if (TOP(s1) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s2, temp);
                    }
                    else {
                        push(&s1, temp);
                    }
                }
                else {
                    if (isEmpty(s3)) {
                        push(&s3, temp);
                    }                    
                    else if (TOP(s3) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s2, temp);
                    }
                    else {
                        push(&s3, temp);
                    }                    
                }
            }
        }
        else if (Si == 3) {
            if (isEmpty(s3)) {
                printf("Menara kosong\n");
            }
            else {
                pop(&s3, &temp);
                if (Di == 2) {
                    if (isEmpty(s2)) {
                        push(&s2, temp);
                    }                    
                    else if (TOP(s2) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s3, temp);
                    }
                    else {
                        push(&s2, temp);
                    }
                }
                else {
                    if (isEmpty(s1)) {
                        push(&s1, temp);
                    }                    
                    else if (TOP(s1) < temp) {
                        printf("Piringan tidak dapat dipindah\n");
                        push(&s3, temp);
                    }
                    else {
                        push(&s1, temp);
                    }                    
                }
            }
        }                
    }

    printf("Menara 1: "); DisplayStack(s1); printf("\n");
    printf("Menara 2: "); DisplayStack(s2); printf("\n");    
    printf("Menara 3: "); DisplayStack(s3); printf("\n");    
}