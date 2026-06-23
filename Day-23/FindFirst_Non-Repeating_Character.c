#include <stdio.h>
#include <string.h>

void findFirstNonRepeatingEasy(char *str) {
    int len = strlen(str);

    // Loop through each character in the string
    for (int i = 0; i < len; i++) {
        int count = 0;

        // Count how many times str[i] appears in the whole string
        for (int j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }

        // If it appears only once, it's our first non-repeating character
        if (count == 1) {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            return; // Exit the function immediately
        }
    }

    printf("All characters are repeating or the string is empty.\n");
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    findFirstNonRepeatingEasy(str);

    return 0;
}