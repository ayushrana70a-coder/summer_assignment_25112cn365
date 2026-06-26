#include <stdio.h>
#include <string.h>

void sortNames(char names[][50], int n) {
    char temp[50];

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // If names[j] comes alphabetically after names[j+1], swap them
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;

    printf("How many names do you want to enter? ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    // Allocate a 2D array: 'n' names, each up to 49 characters long
    char names[n][50]; 

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        // Remove trailing newline character from fgets
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Sort the array of names
    sortNames(names, n);

    printf("\nNames in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}