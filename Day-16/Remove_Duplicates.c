#include <stdio.h>

int main() {
    int n;

    // 1. Get the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // 2. Get the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // --- REMOVE DUPLICATES LOGIC START ---

    int unique_size = 0; // Tracks the size of the array without duplicates

    for (int i = 0; i < n; i++) {
        int is_duplicate = 0;

        // Check if the current element arr[i] already exists in the unique part
        for (int j = 0; j < unique_size; j++) {
            if (arr[i] == arr[j]) {
                is_duplicate = 1; // Found a duplicate!
                break;
            }
        }

        // If it's not a duplicate, keep it in the array
        if (is_duplicate == 0) {
            arr[unique_size] = arr[i];
            unique_size++;
        }
    }

    // --- REMOVE DUPLICATES LOGIC END ---

    // 3. Print the array with duplicates removed
    printf("Array after removing duplicates: ");
    for (int i = 0; i < unique_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}