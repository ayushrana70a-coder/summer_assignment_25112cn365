#include <stdio.h>

// Recursive function
int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1; 
    }
    return n * factorial(n - 1); 
}

int main() {
    int num;

    // Ask user for input
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Calculate and print the result
    printf("Factorial of %d is %d\n", num, factorial(num));

    return 0;
}