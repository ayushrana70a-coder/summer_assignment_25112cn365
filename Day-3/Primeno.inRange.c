#include <stdio.h>
#include <stdbool.h>
int main() {
    int num,lower, upper;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);
    
    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (num = lower; num <= upper; num++) {
        if (num < 2) continue;// Skip numbers less than 2
        bool isPrime = true;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}