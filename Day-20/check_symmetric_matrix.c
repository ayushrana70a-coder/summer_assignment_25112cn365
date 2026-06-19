#include <stdio.h>

int main() {
    int rows, cols;
    int isSymmetric = 1; // Assume the matrix is symmetric initially (1 = True)

    // Ask user for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Rule 1: A symmetric matrix must be square
    if (rows != cols) {
        printf("\nThe matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    int matrix[rows][cols];

    // Input elements for the matrix
    printf("\nEnter elements for the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Checking for symmetry
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Compare element at (i, j) with element at (j, i)
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch, set flag to False
                break;           // Break the inner loop
            }
        }
        if (isSymmetric == 0) {
            break; // Break the outer loop if already determined non-symmetric
        }
    }

    // Displaying the matrix
    printf("\nYour Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Final Output
    if (isSymmetric == 1) {
        printf("\nThe matrix IS a symmetric matrix.\n");
    } else {
        printf("\nThe matrix is NOT a symmetric matrix.\n");
    }

    return 0;
}