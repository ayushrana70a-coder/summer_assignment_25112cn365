#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        char ch = 'A'; // Reset character to 'A' at the start of each row
        
        // Inner loop to print characters from 'A' up to the current row length
        for (int j = 1; j <= i; j++) {
            printf("%c", ch);
            ch++; // Move to the next alphabet ('A' becomes 'B', etc.)
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}