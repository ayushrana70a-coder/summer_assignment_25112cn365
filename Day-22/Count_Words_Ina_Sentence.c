#include <stdio.h>
#include <stdbool.h>

int countWords(char str[]) {
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        // Check for whitespace characters (space, tab, newline)
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            inWord = false;
        } 
        // If the character is not a space and we aren't already inside a word
        else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    // fgets is used to read the entire line, including spaces
    fgets(sentence, sizeof(sentence), stdin);

    int words = countWords(sentence);
    printf("Total number of words: %d\n", words);

    return 0;
}