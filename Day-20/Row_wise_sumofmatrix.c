#include <stdio.h>

int main() {
    int rows, cols;

    // Ask  for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Input elements for the matrix
    printf("\nEnter elements for the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
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

    // Calculating and printing Row-wise sum
    printf("\n--- Row-wise Sum ---\n");
    for (int i = 0; i < rows; i++) {
        int row_sum = 0; // Reset sum to 0 for each new row
        
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        
        printf("Sum of Row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}