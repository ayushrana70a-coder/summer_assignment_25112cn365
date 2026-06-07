#include <stdio.h>

int main() {
    int rows = 4; // Total rows to print

    for (int i = 1; i <= rows; i++) {
        char ch = 'A';

        // 1. Print increasing characters
        // Row 1 goes to 'B' (i + 1), Row 2 to 'C', etc.
        for (int j = 1; j <= i + 1; j++) {
            printf("%c", ch);
            ch++;
        }
        
        // Backtrack the character twice to start the decreasing sequence
        ch -= 2; 
        
        // 2. Print decreasing characters back down to 'A'
        for (int j = 1; j <= i; j++) {
            printf("%c", ch);
            ch--;
        }
        
        // Move to the next line after completing the row
        printf("\n");
    }

    return 0;
}