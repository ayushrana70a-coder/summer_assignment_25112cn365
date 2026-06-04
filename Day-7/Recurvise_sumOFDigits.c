#include <stdio.h>

// Recursive function to calculate sum of digits
int sum_of_digits(int n) {
    // Base case: if the number becomes 0, stop
    if (n == 0) {
        return 0;
    }
    // Recursive case: get the last digit + call function for remaining digits
    return (n % 10) + sum_of_digits(n / 10);
}

int main() {
    int num;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers by converting them to positive
    if (num < 0) {
        num = -num;
    }

    // Calculate and print the result
    printf("Sum of digits is %d\n", sum_of_digits(num));

    return 0;
}