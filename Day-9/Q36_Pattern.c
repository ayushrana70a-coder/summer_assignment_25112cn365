#include <stdio.h>

int main() {
    int size = 5;

    // Outer loop for rows
    for (int i = 1; i <= size; i++) {
        
        // Inner loop for columns
        for (int j = 1; j <= size; j++) {
            
            // Print star if it's the boundary of the square
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                // Print space for the hollow inside
                printf(" ");
            }
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}