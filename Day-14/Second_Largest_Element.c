#include <stdio.h>

int main() {
    int size, temp;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Array must have at least two elements.\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // --- Easy Method: Sort the array from largest to smallest ---
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // If the next element is bigger, swap them
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // --- Find the second largest distinct element ---
    int largest = arr[0];
    int secondLargest = -1; // Placeholder if no second largest exists
    
    for (int i = 1; i < size; i++) {
        // Look for the first number that is strictly smaller than the largest
        if (arr[i] != largest) {
            secondLargest = arr[i];
            break; // Found it! Stop looking.
        }
    }

    // Display results
    if (secondLargest == -1) {
        printf("\nThere is no distinct second largest element.\n");
    } else {
        printf("\nLargest element = %d\n", largest);
        printf("Second largest element = %d\n", secondLargest);
    }

    return 0;
}