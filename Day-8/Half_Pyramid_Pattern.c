#include <stdio.h>

int main() {
    int rows;

    // Ask the user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the rows
    for (int i = 1; i <= rows; ++i) {
        
        // Inner loop handles the number of columns (stars) in each row
        for (int j = 1; j <= i; ++j) {
            printf("* ");
        }
        
        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
}