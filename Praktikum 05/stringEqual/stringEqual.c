#include "boolean.h"
#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

int main(){
    int N; scanf("%d", &N);
    STARTWORD();
    int i;
    if(currentWord.TabWord[4] == 'U'){
        printf("Moving %d square upwards\n", N);
    }
    else if(currentWord.TabWord[4] == 'D'){
        printf("Moving %d square downwards\n", N);
    }
    else if(currentWord.TabWord[4] == 'L'){
        printf("Moving %d square leftwards\n", N);
    }
    else if(currentWord.TabWord[4] == 'R'){
        printf("Moving %d square rightwards\n", N);
    }
}