#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = rows; i >= 1; i--) {
        
        // 1. Print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        
        // 2. Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        
        // Move to the next line
        printf("\n");
    }

    return 0;
}