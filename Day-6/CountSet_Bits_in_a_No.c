#include <stdio.h>

int main() {
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    int originalNum = n; // Keep track of the original value for the print statement

    while (n > 0) {
        count += (n & 1); // Add 1 to count if the last bit is 1
        n = n >> 1;       // Right shift by 1 bit to check the next position
    }

    printf("Number of set bits in %d is: %d\n", originalNum, count);
    return 0;
}