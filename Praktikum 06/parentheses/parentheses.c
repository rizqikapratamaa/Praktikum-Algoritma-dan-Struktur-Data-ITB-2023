#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include "stack.h"

int main() {
    char kurung[100];
    int cnt = 0;
    Stack kur;
    int i, j, temp, deep = 0, idct = 0;

    START();
    while(currentChar != MARK && currentChar != BLANK){
        kurung[cnt] = currentChar;
        cnt++;
        ADV();
    }

    CreateEmpty(&kur);  

    for (i = 0; i < cnt; i++) {
        if (kurung[i] == '(') {
            idct++;
        }
        else if (kurung[i] == ')') {
            idct--;
        }

        if (deep < idct) {
            deep = idct;
        }
    }

    if (idct == 0) {
        printf("%d\n", deep);
    }

    else {
        printf("%d\n", -1);
    }

}