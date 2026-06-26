#include <stdio.h>
#include <string.h>

void sortWordsByLength(char words[][50], int count) {
    char temp[50];

    // Bubble Sort based on string length
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // Compare lengths of adjacent words
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap the words if the current one is longer than the next one
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

int main() {
    char str[200];
    char words[50][50]; // Array to hold up to 50 words, each 49 chars long
    int count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    // Step 1: Split the sentence into individual words using spaces as delimiters
    char *token = strtok(str, " ");
    while (token != NULL && count < 50) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    // Step 2: Sort the words array by length
    sortWordsByLength(words, count);

    // Step 3: Print the sorted words
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (Length: %lu)\n", words[i], strlen(words[i]));
    }

    return 0;
}