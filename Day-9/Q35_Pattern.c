#include <stdio.h>

int main() {
    // Outer loop runs from character 'A' to 'E'
    for (char i = 'A'; i <= 'E'; i++) {
        
        // Inner loop prints the current character 'i'
        // It runs based on the row position (1st row = 1 time, 2nd row = 2 times, etc.)
        for (char j = 'A'; j <= i; j++) {
            printf("%c", i);
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}