#include <stdio.h>

// Global variable to store the reversed number
int reversed_num = 0;

// Recursive function to reverse the number
void reverse_number(int n) {
    // Base case: stop when the number becomes 0
    if (n == 0) {
        return;
    }
    
    // Get the last digit and build the reversed number
    reversed_num = (reversed_num * 10) + (n % 10);
    
    // Recursive call with the remaining digits
    reverse_number(n / 10);
}

int main() {
    int num;

    // Ask user for input
    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    // Call the recursive function
    reverse_number(num);

    // Print the result
    printf("Reversed number: %d\n", reversed_num);

    return 0;
}