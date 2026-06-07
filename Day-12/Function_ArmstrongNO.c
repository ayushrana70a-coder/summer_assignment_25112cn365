#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum = num, remainder, result = 0, count = 0;

    // 1. Count the number of digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    // 2. Calculate the sum of the power of individual digits
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        
        // round() is used because pow() returns a double, which can sometimes have tiny rounding errors
        result += pow(remainder, count); 
        
        temp /= 10;
    }

    // 3. If the sum matches the original number, it's an Armstrong number
    return (result == originalNum);
}

int main() {
    int Number;

    // Get input from the user
    printf("Enter an integer: ");
    scanf("%d", &Number);

    // Call the function and print the result
    if (isArmstrong(Number)) {
        printf("%d is an Armstrong number\n", Number);
    } else {
        printf("%d is NOT an Armstrong number\n", Number);
    }

    return 0;
}