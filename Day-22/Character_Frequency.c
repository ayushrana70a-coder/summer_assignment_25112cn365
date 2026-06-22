#include <stdio.h>
#include <string.h>

void countCharacterFrequency(char str[]) {
    // Array to store the frequency of all 256 ASCII characters, initialized to 0
    int frequency[256] = {0};

    // Count the frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        // Cast the character to unsigned char to avoid negative indexing
        int asciiValue = (unsigned char)str[i];
        frequency[asciiValue]++;
    }

    // Print the frequencies of characters that appeared at least once
    printf("\nCharacter Frequencies:\n");
    printf("---------------------\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            // Special handling to make spaces and newlines readable in the output
            if (i == ' ') {
                printf("' ' (space) : %d\n", frequency[i]);
            } else if (i == '\n') {
                printf("'\\n' (newline) : %d\n", frequency[i]);
            } else if (i == '\t') {
                printf("'\\t' (tab) : %d\n", frequency[i]);
            } else {
                printf("'%c'         : %d\n", i, frequency[i]);
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    // fgets reads the entire line including spaces
    fgets(str, sizeof(str), stdin);

    countCharacterFrequency(str);

    return 0;
}