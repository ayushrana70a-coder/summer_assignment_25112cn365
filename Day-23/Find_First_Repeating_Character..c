#include <stdio.h>
#include <string.h>

void findFirstRepeating(char *str) {
    int len = strlen(str);

    // Loop through each character
    for (int i = 0; i < len; i++) {
        // Check the rest of the string to see if the same character appears again
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                printf("The first repeating character is: '%c'\n", str[i]);
                return; // Stop as soon as we find the first duplicate
            }
        }
    }

    printf("There are no repeating characters.\n");
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    findFirstRepeating(str);

    return 0;
}