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

    // --- BUBBLE SORT LOGIC START ---
    
    // Outer loop controls the number of passes
    for (int i = 0; i < n - 1; i++) {
        
        // Inner loop compares adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // --- BUBBLE SORT LOGIC END ---

    // 3. Print the sorted array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}