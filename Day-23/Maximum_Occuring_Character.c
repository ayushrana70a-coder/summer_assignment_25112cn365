#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void findMaxOccurringChar(char *str) {
    int count[NO_OF_CHARS] = {0}; // Initialize all counts to 0
    int len = strlen(str);
    int maxCount = 0;
    char maxChar = ' ';

    // Step 1: Count the frequency of each character
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }

    // Step 2: Find the maximum count and its corresponding character
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)str[i]] > maxCount) {
            maxCount = count[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    if (maxCount > 0) {
        printf("The maximum occurring character is '%c' (appears %d times).\n", maxChar, maxCount);
    } else {
        printf("The string is empty.\n");
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    findMaxOccurringChar(str);

    return 0;
}