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

    // --- INSERTION SORT (KEY METHOD) LOGIC START ---

    // Start from the second element (index 1) because a single element (index 0) is already sorted
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Pick the element to be inserted
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than the key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;           // Move to the previous element
        }
        
        // Put the key into its correct sorted position
        arr[j + 1] = key;
    }

    // --- INSERTION SORT LOGIC END ---

    // 3. Print the sorted array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}