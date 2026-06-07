#include <stdio.h>

// Function to check if a number is a perfect number
// Returns 1 if perfect, 0 if not perfect
int isPerfect(int num) {
    int sum = 0;

    // Loop to find all divisors of the number (excluding itself)
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum = sum + i; // Add the divisor to the sum
        }
    }

    // If the sum of divisors equals the original number, it's perfect
    if (sum == num) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Enter a number to check: ");
    scanf("%d", &num);

    // Call the function and check the result
    if (isPerfect(num)) {
        printf("%d is a Perfect Number\n", num);
    } else {
        printf("%d is NOT a Perfect Number\n", num);
    }

    return 0;
}