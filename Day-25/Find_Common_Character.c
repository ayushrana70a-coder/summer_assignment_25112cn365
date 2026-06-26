#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void findCommonCharacters(char *str1, char *str2) {
    int presentInStr1[NO_OF_CHARS] = {0};
    int presentInStr2[NO_OF_CHARS] = {0};
    int foundCommon = 0;

    // Step 1: Mark characters present in the first string
    for (int i = 0; str1[i] != '\0'; i++) {
        presentInStr1[(unsigned char)str1[i]] = 1;
    }

    // Step 2: Mark characters present in the second string
    for (int i = 0; str2[i] != '\0'; i++) {
        presentInStr2[(unsigned char)str2[i]] = 1;
    }

    // Step 3: If a character is marked in both arrays, it is common
    printf("Common characters are: ");
    for (int i = 0; i < NO_OF_CHARS; i++) {
        if (presentInStr1[i] && presentInStr2[i]) {
            // Avoid printing spaces as a common character visually
            if (i != ' ') {
                printf("'%c' ", i);
            } else {
                printf("'(space)' ");
            }
            foundCommon = 1;
        }
    }

    if (!foundCommon) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    findCommonCharacters(str1, str2);

    return 0;
}