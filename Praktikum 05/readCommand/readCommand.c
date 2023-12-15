#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int main() {
    int totalChar = 0;
    START();
    while (currentChar == BLANK) {
        ADV();
    }
    while (!EOP) {
        printf("%c", currentChar);
        totalChar++;
        ADV();
    }
    printf("\n%d\n", totalChar);
    return 0;
}
