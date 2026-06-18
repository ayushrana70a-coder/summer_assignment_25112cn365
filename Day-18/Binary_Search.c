#include <stdio.h>

int main() {
    int n, target;
    int found = 0;

    // 1. Get the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // 2. Get the array elements (MUST BE SORTED)
    printf("Enter %d elements in SORTED (ascending) order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Get the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // --- BINARY SEARCH LOGIC START ---
    
    int low = 0;          // Points to the start of the array
    int high = n - 1;     // Points to the end of the array

    while (low <= high) {
        // Calculate the middle index
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            printf("Element found at index: %d\n", mid);
            found = 1;
            break; // Stop searching since we found it
        }

        // If target is smaller than mid, it can only be in the left half
        if (target < arr[mid]) {
            high = mid - 1;
        }
        // If target is greater than mid, it can only be in the right half
        else {
            low = mid + 1;
        }
    }

    // If low crosses high, the element is not in the array
    if (found == 0) {
        printf("Element not found in the array.\n");
    }

    // --- BINARY SEARCH LOGIC END ---

    return 0;
}