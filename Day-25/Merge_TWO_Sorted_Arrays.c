#include <stdio.h>

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for merged array

    // Traverse both arrays and copy the smaller element
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1[], if any
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2[], if any
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // The size of the merged array must be the sum of both sizes
    int merged[n1 + n2];

    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    printf("Array 1: ");
    printArray(arr1, n1);

    printf("Array 2: ");
    printArray(arr2, n2);

    printf("Merged Sorted Array: ");
    printArray(merged, n1 + n2);

    return 0;
}