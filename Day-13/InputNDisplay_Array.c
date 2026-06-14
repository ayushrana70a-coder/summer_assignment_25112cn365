#include <stdio.h>

int main() {
    int size;

    // 1. Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; // Create the array

    // 2. Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }

    // 3. Display the elements of the array
    printf("\nThe elements in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}