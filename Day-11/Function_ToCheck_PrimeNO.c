#include <stdio.h>

// Short function to check prime: returns 1 for prime, 0 for non-prime
int isPrime(int n) {
    if (n <= 1) return 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // Found a factor, not prime
    }
    return 1; // Prime
}

int main() {
    int num; // Example number
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &num);
    
    if (isPrime(num)) {
        printf("%d is Prime\n", num);
    } else {
        printf("%d is Not Prime\n", num);
    }
    
    return 0;
}