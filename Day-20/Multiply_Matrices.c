#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    //  dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Matrix multiplication rule check
    if (c1 != r2) {
        printf("\nError! Columns of first matrix must equal rows of second matrix.\n");
        return 1; 
    }

    int first[r1][c1], second[r2][c2], result[r1][c2];

    // Input elements for the first matrix
    printf("\nEnter elements for the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &first[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements for the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &second[i][j]);
        }
    }

    // Initializing elements of result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiplying matrices using 3 nested loops
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    // Displaying the result matrix
    printf("\nResultant Product Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}