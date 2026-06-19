#include <stdio.h>

int main() {
    char str[100];

    printf("Enter a string in lowercase: ");
    // The space before %[^\n] clears any leftover newline characters from the buffer
    scanf(" %[^\n]", str); 

    // Loop through each character of the string until the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is currently lowercase (between 'a' and 'z')
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Convert to uppercase by subtracting 32
        }
    }

    // Display the modified uppercase string
    printf("Uppercase string: %s\n", str);

    return 0;
}