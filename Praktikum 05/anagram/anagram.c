#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

#define MAX_WORDS 100

void sortWord(Word *word) {
    int i, j;
    char temp;
    for (i = 0; i < word->Length-1; i++) {
        for (j = i+1; j < word->Length; j++) {
            if (word->TabWord[i] > word->TabWord[j]) {
                temp = word->TabWord[i];
                word->TabWord[i] = word->TabWord[j];
                word->TabWord[j] = temp;
            }
        }
    }
}

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

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    int numAnagrams = 0;
    int i;

    STARTWORD();
    while (!EndWord) {
        words[numWords] = currentWord;
        sortWord(&words[numWords]);
        numWords++;
        ADVWORD();
    }

    sortWords(words, numWords);

    for (i = 1; i < numWords; i++) {
        if (compareWords(words[i], words[i-1]) == 0) {
            int j = i;
            while (j < numWords && compareWords(words[j], words[j-1]) == 0) {
                j++;
            }
            numAnagrams += (j - i) * (j - i + 1) / 2;
            i = j;
        }
    }

    printf("%d\n", numAnagrams);

    return 0;
}