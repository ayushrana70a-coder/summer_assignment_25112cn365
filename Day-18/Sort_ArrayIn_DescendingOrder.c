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

    // --- DESCENDING BUBBLE SORT LOGIC START ---
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            // CRITICAL CHANGE: Change '>' to '<' for descending order
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // --- DESCENDING BUBBLE SORT LOGIC END ---

    // 3. Print the sorted array
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}