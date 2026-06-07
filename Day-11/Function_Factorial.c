#include <stdio.h>

// Easy function to find factorial
long findFactorial(int n) {
    long fact = 1;

    // Loop from 1 up to n and multiply
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

int main() {
    int num;
    long result;
    // Taking input from the user
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    // Call the function
    result = findFactorial(num);

    printf("Factorial of %d is %ld\n", num, result);

    return 0;
}