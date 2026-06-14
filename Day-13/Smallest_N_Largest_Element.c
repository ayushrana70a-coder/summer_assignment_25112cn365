#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]; 

    // 2. Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 3. Assume the first element is both the largest and smallest
    int largest = arr[0];
    int smallest = arr[0];

    // 4. Compare with the rest of the elements
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];  // Found a bigger number, update largest
        }
        if (arr[i] < smallest) {
            smallest = arr[i]; // Found a smaller number, update smallest
        }
    }

    // 5. Display the results
    printf("\nLargest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}