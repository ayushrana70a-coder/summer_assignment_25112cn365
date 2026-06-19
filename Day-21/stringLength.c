#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    // Ask user for input
    printf("Enter a string: ");
    // Using %[^\n] allows the program to read spaces (unlike scanf("%s"))
    scanf("%[^\n]", str); 

    // Loop until the null terminator '\0' is reached
    while (str[length] != '\0') {
        length++; // Increment the counter for each character
    }

    // Display the result
    printf("The length of the string is: %d\n", length);

    return 0;
}