#include <stdio.h>

int main() {
    char str[100];
    int length = 0;
    int start, end;
    char temp;

    // Ask user for input
    printf("Enter a string: ");
    scanf("%[^\n]", str); // Reads the string including spaces

    // Step 1: Find the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Step 2: Reverse the string using two pointers
    start = 0;
    end = length - 1; // Last character is at index (length - 1)

    while (start < end) {
        // Swap characters at start and end
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move the pointers toward the center
        start++;
        end--;
    }

    // Display the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}