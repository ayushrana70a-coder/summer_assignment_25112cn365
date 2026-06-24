#include <stdio.h>
#include <string.h>

void compressString(char *str) {
    int len = strlen(str);
    
    // If the string is empty, do nothing
    if (len == 0) {
        printf("String is empty.\n");
        return;
    }

    char compressed[200] = ""; // Array to store the compressed string
    int count = 1;
    int j = 0; // Index tracker for the compressed string

    for (int i = 0; i < len; i++) {
        // If the next character is the same, increase the count
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            // Otherwise, append the character and its count to the compressed array
            j += sprintf(&compressed[j], "%c%d", str[i], count);
            count = 1; // Reset count for the next unique character
        }
    }

    // A good compression rule: only use the compressed version if it's actually shorter
    if (strlen(compressed) < len) {
        printf("Compressed string: %s\n", compressed);
    } else {
        printf("Compressed string is not shorter. Original string: %s\n", str);
    }
}

int main() {
    char str[100];

    printf("Enter a string to compress (e.g., aabcccccaaa): ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    compressString(str);

    return 0;
}