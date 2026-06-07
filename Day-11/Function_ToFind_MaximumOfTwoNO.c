#include <stdio.h>

// Function declaration
int findMaximum(int num1, int num2);

int main() {
    int a, b, max;

    // Inputting two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Calling the function and passing 'a' and 'b' as arguments
    max = findMaximum(a, b);

    // Displaying the maximum number
    printf("The maximum number is: %d\n", max);

    return 0;
}

// Function definition to find the maximum
int findMaximum(int num1, int num2) {
    if (num1 > num2) {
        return num1; // If num1 is greater, return num1
    } else {
        return num2; // Otherwise, num2 is greater or equal, so return num2
    }
}