#include <stdio.h>

int main() {
    int size;
    int evenCount = 0;
    int oddCount = 0;

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

    // 3. Count even and odd numbers
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++; // Increment even count if remainder is 0
        } else {
            oddCount++;  // Increment odd count otherwise
        }
    }

    // 4. Display the results
    printf("\nTotal Even elements = %d\n", evenCount);
    printf("Total Odd elements = %d\n", oddCount);

    return 0;
}