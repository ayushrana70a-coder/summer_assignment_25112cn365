#include <stdio.h>

int main() {
    int size, sum = 0;
    float average;

    // 1. Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // Create the array

    // 2. Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 3. Calculate the sum
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i]; // Add each element to sum
    }

    // 4. Calculate the average
    // (float) is used to convert sum to a decimal so the division is accurate
    average = (float)sum / size; 

    // 5. Display the results
    printf("\nSum of all elements = %d\n", sum);
    printf("Average of all elements = %.2f\n", average);

    return 0;
}