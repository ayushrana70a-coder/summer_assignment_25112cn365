#include <stdio.h>

int main() {
    int n, d;

    // 1. Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 

    // 2. Get the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Get the number of rotations
    printf("Enter the number of positions to rotate right: ");
    scanf("%d", &d);

    // Handle cases where d is greater than the array size
    d = d % n;

    // --- RIGHT ROTATION LOGIC START ---
    
    // Step A: Copy the LAST 'd' elements into a temporary array
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[n - d + i];
    }

    // Step B: Shift the remaining elements to the right
    // (We loop backwards so we don't overwrite elements we still need to move)
    for (int i = n - 1; i >= d; i--) {
        arr[i] = arr[i - d];
    }

    // Step C: Copy the elements from the temp array to the front
    for (int i = 0; i < d; i++) {
        arr[i] = temp[i];
    }
    
    // --- RIGHT ROTATION LOGIC END ---

    // 4. Print the final rotated array
    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}