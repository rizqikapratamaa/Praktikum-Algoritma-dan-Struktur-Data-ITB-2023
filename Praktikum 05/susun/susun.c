#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

#define MAX_WORDS 100

int compareWords(Word a, Word b) {
    int i = 0;
    while (i < a.Length && i < b.Length) {
        if (a.TabWord[i] < b.TabWord[i]) {
            return -1;
        } else if (a.TabWord[i] > b.TabWord[i]) {
            return 1;
        }
        i++;
    }
    if (a.Length < b.Length) {
        return -1;
    } else if (a.Length > b.Length) {
        return 1;
    } else {
        return 0;
    }
}

void sortWords(Word words[], int numWords) {
    int i, j;
    Word temp;
    for (i = 0; i < numWords-1; i++) {
        for (j = i+1; j < numWords; j++) {
            if (compareWords(words[i], words[j]) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
    printf("\n");
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    int i;

    STARTWORD();
    while (!EndWord) {
        words[numWords] = currentWord;
        numWords++;
        ADVWORD();
    }

    sortWords(words, numWords);

    for (i = 0; i < numWords; i++) {
        printWord(words[i]);
    }

    return 0;
}