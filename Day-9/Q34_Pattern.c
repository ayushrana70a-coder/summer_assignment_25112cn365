#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop starts at 5 and counts down to 1
    for (int i = rows; i >= 1; i--) {
        
        // Inner loop always starts at 1 and counts up to the current value of 'i'
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}