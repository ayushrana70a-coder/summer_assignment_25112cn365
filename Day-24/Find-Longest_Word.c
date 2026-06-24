#include <stdio.h>
#include <string.h>

void findLongestWord(char *str) {
    int len = strlen(str);
    int maxLen = 0, maxStartIndex = 0;
    int currLen = 0, currStartIndex = 0;

    for (int i = 0; i <= len; i++) {
        // If the character is not a space and not the end of the string, it's part of the current word
        if (str[i] != ' ' && str[i] != '\0') {
            if (currLen == 0) {
                currStartIndex = i; // Mark where the current word begins
            }
            currLen++;
        } 
        // We hit a space or the end of the string (end of a word)
        else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStartIndex = currStartIndex;
            }
            currLen = 0; // Reset for the next word
        }
    }

    // Print the longest word using its start index and length
    printf("The longest word is: ");
    for (int i = maxStartIndex; i < maxStartIndex + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\nLength: %d\n", maxLen);
}

int main() {
    char str[200];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    findLongestWord(str);

    return 0;
}