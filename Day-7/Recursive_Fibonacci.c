#include <stdio.h>

// Recursive function to get the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    printf("Enter the number of terms to print: ");
    scanf("%d", &terms);

    printf("Fibonacci Series: ");
    
    // Loop to print each term up to the user's input
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}