#include <stdio.h>
#include <math.h>
int main() {
    int lower, upper, num, digit, sum, count, temp;
    printf("Enter range (lower - upper): ");
    scanf("%d %d", &lower, &upper);

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);
    for(num = lower; num <= upper; num++) {
        temp = num;
        count = 0;
        sum = 0;

        while(temp > 0) {
            count++;
            temp /= 10;
        }

        temp = num;
        while(temp > 0) {
            digit = temp % 10;
            sum += pow(digit, count);
            temp /= 10;
        }

        if(sum == num)
            printf("%d ", num);
    }
    return 0;
}