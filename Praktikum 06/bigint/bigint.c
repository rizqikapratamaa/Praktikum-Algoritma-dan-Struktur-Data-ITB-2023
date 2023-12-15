#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int integerize(char c){
    return c-48;
}

boolean isLess(Stack s1, Stack s2){
    if (s1.TOP<s2.TOP) return true;
    if(s1.TOP > s2.TOP) return false;
    int a, b;
    while (!IsEmpty(s1)){
        Pop(&s1, &a); Pop(&s2, &b);
        if(a < b) return true;
        if(a > b) return false;
    }
    return false;
}

void reduce(Stack s1, Stack s2, Stack*s3){
    int a, b;
    boolean carry = false;
    while(!IsEmpty(s1) && !IsEmpty(s2)){
        Pop(&s1, &a);
        Pop(&s2, &b);
        if(carry) a--;
        if(a >= b){
            a-=b;carry=false;
        } else {
            a += 10 - b;
            carry = true;
        }
        Push(s3, a);
    }
    while(!IsEmpty(s1)){
        Pop(&s1, &a);
        if(carry) a--;
        if(a < 0){
            a += 10;
            carry = true;
        } else {
            carry = false;
        }
        Push(s3, a);
    }
}

int main(){
    Stack s1, s2, s3;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&s3);
    char *s = (char*)malloc(101*sizeof(char));
    scanf("%s", s);
    int i=0,cnt=0;while(integerize(s[i])>=0){
        Push(&s1,integerize(s[i]));i++;
    }
    scanf("%s",s);
    i=0;while(integerize(s[i])>=0){
        Push(&s2,integerize(s[i]));i++;
    }
    boolean stat = isLess(s1,s2);
    if(stat){
        reduce(s2,s1,&s3);printf("-");
    } else {
        reduce (s1,s2,&s3);
    }
    while(!IsEmpty(s3)){
        Pop(&s3,&i);
        if(!(i==0&&cnt==0)){
            printf("%d",i);cnt++;
        }
    }
    if(cnt==0){
        printf("%d",i);
    }
    printf("\n");
    return 0;
}

