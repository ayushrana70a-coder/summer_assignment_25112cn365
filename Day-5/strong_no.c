#include <stdio.h>

int main() {
    int num, originalNum, rem, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num; // Store the original number for final comparison

    // Process each digit of the number
    while (num > 0) {
        rem = num % 10; // Get the last digit

        // Calculate the factorial of the digit
        int fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact *= i;
        }

        sum += fact;   // Add the factorial to the total sum
        num = num / 10; // Remove the last digit from the number
    }

    // Check if the sum of factorials equals the original number
    if (sum == originalNum) {
        printf("%d is a Strong Number.\n", originalNum);
    } else {
        printf("%d is NOT a Strong Number.\n", originalNum);
    }

    return 0;
}