#include <stdio.h>

int main() {
    int n, maxPrime = -1;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Loop through all numbers from 2 up to n
    for (int i = 2; i <= n; i++) {
        
        // 1. Check if 'i' is a factor of n
        if (n % i == 0) {
            int isPrime = 1; // Assume 'i' is prime
            
            // 2. Check if 'i' is actually a prime number
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = 0; // It's not prime
                    break;
                }
            }
            
            // 3. If it is prime, update our max variable
            if (isPrime == 1) {
                maxPrime = i;
            }
        }
    }

    printf("The largest prime factor is: %d\n", maxPrime);

    return 0;
}