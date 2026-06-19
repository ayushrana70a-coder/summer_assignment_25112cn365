#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix1[rows][cols], matrix2[rows][cols], difference[rows][cols];

    // Input elements for the first matrix
    printf("\nEnter elements for the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements for the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Subtracting the second matrix from the first
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Displaying the result
    printf("\nDifference of the two matrices (Matrix1 - Matrix2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", difference[i][j]);
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}
