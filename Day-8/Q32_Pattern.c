#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop to print the row number 'i' exactly 'i' times
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}