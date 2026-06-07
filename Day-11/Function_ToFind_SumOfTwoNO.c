#include <stdio.h>

// Function declaration/prototype
int findSum(int num1, int num2);

int main() {
    int a, b, sum;

    // Taking input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Calling the function and storing the returned value
    sum = findSum(a, b);

    // Displaying the result
    printf("The sum of %d and %d is: %d\n", a, b, sum);

    return 0;
}

// Function definition to calculate sum
int findSum(int num1, int num2) {
    int result;
    result = num1 + num2;
    return result; // Returns the calculated sum back to main()
}