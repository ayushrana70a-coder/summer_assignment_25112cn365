#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function Prototypes (Custom string operations without using <string.h>)
int customStrLen(char str[]);
void customStrCpy(char dest[], char src[]);
void customStrConcat(char dest[], char src[]);
int customStrCmp(char str1[], char str2[]);
void customStrRev(char str[]);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    char str1[MAX_SIZE * 2]; // Extra padding space for safe concatenation overrides
    char str2[MAX_SIZE];

    while (1) {
        printf("\n====================================");
        printf("\n      STRING OPERATIONS SYSTEM      ");
        printf("\n====================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Strings (Join)");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); // Clear trailing newline from the input stream buffer

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, MAX_SIZE, stdin);
                str1[customStrLen(str1) - 1] = '\0'; // Strip trailing newline character safely
                printf("Length of the string: **%d** characters.\n", customStrLen(str1));
                break;

            case 2:
                printf("\nEnter Source String to copy: ");
                fgets(str1, MAX_SIZE, stdin);
                str1[customStrLen(str1) - 1] = '\0';
                
                customStrCpy(str2, str1);
                printf("Copied! Destination String holds: \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter First String (Destination): ");
                fgets(str1, MAX_SIZE, stdin);
                str1[customStrLen(str1) - 1] = '\0';
                
                printf("Enter Second String to append: ");
                fgets(str2, MAX_SIZE, stdin);
                str2[customStrLen(str2) - 1] = '\0';

                customStrConcat(str1, str2);
                printf("Concatenated Result: **\"%s\"**\n", str1);
                break;

            case 4:
                printf("\nEnter First String: ");
                fgets(str1, MAX_SIZE, stdin);
                str1[customStrLen(str1) - 1] = '\0';

                printf("Enter Second String: ");
                fgets(str2, MAX_SIZE, stdin);
                str2[customStrLen(str2) - 1] = '\0';

                int cmpResult = customStrCmp(str1, str2);
                if (cmpResult == 0) {
                    printf("\nResult: Both strings match perfectly! (Identical)\n");
                } else if (cmpResult > 0) {
                    printf("\nResult: First string is larger lexicographically.\n");
                } else {
                    printf("\nResult: Second string is larger lexicographically.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, MAX_SIZE, stdin);
                str1[customStrLen(str1) - 1] = '\0';

                customStrRev(str1);
                printf("Reversed Result: **\"%s\"**\n", str1);
                break;

            case 6:
                printf("\nExiting System. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }
}

// 1. Length algorithm: Count indices manually until hitting the null terminator (\0)
int customStrLen(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 2. Copy algorithm: Duplicate values entry by entry, then slap a manual \0 at the tail end
void customStrCpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

// 3. Concatenation algorithm: Seek to the end of dest, then map src data down onto it
void customStrConcat(char dest[], char src[]) {
    int destLen = customStrLen(dest);
    int i = 0;
    
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

// 4. Comparison algorithm: Check ASCII weight variances item-by-item
int customStrCmp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; // Returns difference of ASCII decimal weights
        }
        i++;
    }
    return 0;
}

// 5. Reverse algorithm: Swapping characters from opposite ends meeting at the middle
void customStrRev(char str[]) {
    int len = customStrLen(str);
    int start = 0;
    int end = len - 1;
    char temp;

    while (start < end) {
        // Structural inline element value swap
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}