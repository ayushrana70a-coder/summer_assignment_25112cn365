#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop to print numbers from 1 up to the current row number 'i'
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Move to the next line after finishing a row
        printf("\n");
    }

    return 0;
}