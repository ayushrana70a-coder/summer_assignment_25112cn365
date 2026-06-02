#include <stdio.h>
int main() {
    int num, i, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for ( i = 1; i < num; i++) { //Loop through all numbers less than n
        if (num% i == 0) {
            sum += i; // Add divisor to sum
        }
    }

    // Check if the sum of divisors equals the number
    if (sum == num) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is NOT a perfect number.\n", num);
    }

    return 0;
}