#include <stdio.h>

int main() {
    int size;
    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    // Ask user for the size of the square matrix
    printf("Enter the size of the square matrix (e.g., 3 for 3x3): ");
    scanf("%d", &size);

    int matrix[size][size];

    // Input elements for the matrix
    printf("\nEnter elements for the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculating diagonal sums
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Condition for Principal Diagonal
            if (i == j) {
                main_diagonal_sum += matrix[i][j];
            }
            
            // Condition for Secondary Diagonal
            if ((i + j) == (size - 1)) {
                secondary_diagonal_sum += matrix[i][j];
            }
        }
    }

    // Displaying the matrix
    printf("\nYour Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Printing the results
    printf("\nSum of Principal Diagonal elements: %d\n", main_diagonal_sum);
    printf("Sum of Secondary Diagonal elements: %d\n", secondary_diagonal_sum);

    return 0;
}