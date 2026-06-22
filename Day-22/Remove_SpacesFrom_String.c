#include <stdio.h>

void removeSpaces(char *str) {
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string
    for (int i = 0; str[i] != '\0'; i++) {
        // If the current character is not a space, move it to the 'count' index
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    
    // Null-terminate the modified string
    str[count] = '\0';
}

int main() {
    // Note: Use a char array, not a string literal (char *str = "...") 
    // because string literals are read-only and will cause a segmentation fault.
    char text[] = "Let's  remove   all the spaces!";
    
    printf("Original: \"%s\"\n", text);
    
    removeSpaces(text);
    
    printf("Modified: \"%s\"\n", text);
    
    return 0;
}