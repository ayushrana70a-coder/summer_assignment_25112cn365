#include <stdio.h>

int main() {
    int size, searchElement, found = 0;

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

    // 3. Get the element to search for
    printf("\nEnter the element you want to search for: ");
    scanf("%d", &searchElement);

    // 4. Perform Linear Search
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchElement) {
            printf("Element found at index position: %d (Element %d)\n", i, i + 1);
            found = 1; 
            break;    
        }
    }

    // 5. If the element was not found
    if (found == 0) {
        printf("Element not found in the array.\n");
    }

    return 0;
}