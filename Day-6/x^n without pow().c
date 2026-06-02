#include <stdio.h>

// Easy recursive function to calculate power
double power(double x, int n) {
    if (n == 0) return 1;               // Anything to the power of 0 is 1
    if (n < 0) return 1 / power(x, -n); // Handle negative powers
    
    return x * power(x, n - 1);         // Multiply x by itself recursively
}

int main() {
    double base;
    int exp;

    // Get the base number from the user
    printf("Enter base number (x): ");
    scanf("%lf", &base);

    // Get the power/exponent from the user
    printf("Enter exponent/power (n): ");
    scanf("%d", &exp);

    // Calculate and print the result
    double result = power(base, exp);
    printf("%.2f raised to the power of %d is: %.5f\n", base, exp, result);

    return 0;
}