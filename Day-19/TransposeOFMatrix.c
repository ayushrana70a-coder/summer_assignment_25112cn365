#include <stdio.h>

int main() {
    int rows, cols;

    // Ask user for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    // Note the swapped dimensions for the transpose matrix: cols x rows
    int transpose[cols][rows]; 

    // Input elements for the matrix
    printf("\nEnter elements for the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transposing the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j]; // Swapping rows and columns
        }
    }

    // Displaying the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Displaying the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {       // Loop runs up to 'cols'
        for (int j = 0; j < rows; j++) {   // Loop runs up to 'rows'
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}