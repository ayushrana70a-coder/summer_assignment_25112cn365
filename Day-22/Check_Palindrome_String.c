#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    // Move pointers towards each other
    while (start < end) {
        // If characters don't match, it's not a palindrome
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true; // Characters matched all the way through
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Reads a line of text, including spaces (prevents buffer overflow with 99)
    scanf("%99s", str); 

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}