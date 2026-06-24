#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void removeDuplicates(char *str) {
    int seen[NO_OF_CHARS] = {0}; // Checklist initialized to 0 (false)
    int targetIndex = 0;         // Tracks where to write the next unique character

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        // If we haven't seen this character yet
        if (seen[ch] == 0) {
            seen[ch] = 1;          // Mark it as seen
            str[targetIndex] = str[i]; // Move it to the active unique position
            targetIndex++;
        }
    }
    
    // Null-terminate the modified string to clear out the leftover old characters
    str[targetIndex] = '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}