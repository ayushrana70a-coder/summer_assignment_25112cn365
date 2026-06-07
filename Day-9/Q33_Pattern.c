#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop starts at 'rows' and decreases by 1 each time
    for (int i = rows; i >= 1; i--) {
        
        // Inner loop prints stars up to the value of 'i'
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}