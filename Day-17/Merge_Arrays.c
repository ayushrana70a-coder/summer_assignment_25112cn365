#include <stdio.h>

int main() {
    int n1, n2;

    // 1. Input for the First Array
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 2. Input for the Second Array
    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- MERGE LOGIC START ---

    // Step A: Create a third array with total combined size
    int n3 = n1 + n2;
    int mergedArr[n3];

    // Step B: Copy elements of the first array into the merged array
    for (int i = 0; i < n1; i++) {
        mergedArr[i] = arr1[i];
    }

    // Step C: Copy elements of the second array into the merged array
    for (int i = 0; i < n2; i++) {
        mergedArr[n1 + i] = arr2[i]; 
        // Index starts at n1 so it continues right after the first array
    }

    // --- MERGE LOGIC END ---

    // 3. Print the final merged array
    printf("The merged array is: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}