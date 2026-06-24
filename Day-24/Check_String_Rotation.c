#include <stdio.h>
#include <string.h>

int checkRotation(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Step 1: If lengths are not equal, they cannot be rotations
    if (len1 != len2) {
        return 0;
    }

    // Step 2: Create a temporary buffer to hold str1 concatenated with itself
    // Size is len1 * 2 + 1 for the null-terminator
    char temp[200]; 
    
    strcpy(temp, str1); // Copy str1 into temp
    strcat(temp, str1); // Append str1 to temp again (temp now holds str1+str1)

    // Step 3: Check if str2 is a substring of the concatenated string
    if (strstr(temp, str2) != NULL) {
        return 1; // str2 is a rotation of str1
    } else {
        return 0; // str2 is not a rotation
    }
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    if (checkRotation(str1, str2)) {
        printf("The strings are rotations of each other.\n");
    } else {
        printf("The strings are NOT rotations of each other.\n");
    }

    return 0;
}