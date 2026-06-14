#include <stdio.h>

int main() {
    int size;
    int count = 0;

    // 1. Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // 2. Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nDuplicate elements in the array are: ");

    // 3. Nested loops to find duplicate elements
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            // If a match is found, it's a duplicate
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                count++;
                break; 
            }
        }
    }

    // 4. If no duplicates were found
    if (count == 0) {
        printf("None");
    }
    printf("\n");

    return 0;
}