#include <stdio.h>

int main() {
    int rows, cols;

    // Ask user for matrix dimensions
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

    // Calculating and printing Column-wise sum
    printf("\n--- Column-wise Sum ---\n");
    for (int j = 0; j < cols; j++) {
        int col_sum = 0; // Reset sum to 0 for each new column
        
        for (int i = 0; i < rows; i++) {
            col_sum += matrix[i][j]; // Notice: i changes while j stays constant
        }
        
        printf("Sum of Column %d = %d\n", j + 1, col_sum);
    }

    return 0;
}