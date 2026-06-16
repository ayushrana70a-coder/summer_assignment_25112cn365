#include <stdio.h>

int main() {
    int n;

    // 1. Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // 2. Get the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // --- MOVE ZEROES LOGIC START ---
    
    int count = 0; // Keeps track of the position for non-zero elements

    // Step A: If the element is non-zero, shift it to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++; 
        }
    }

    // Step B: Fill the remaining space with zeroes
    while (count < n) {
        arr[count] = 0;
        count++;
    }

    // --- MOVE ZEROES LOGIC END ---

    // 3. Print the final modified array
    printf("Array after moving zeroes to end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}