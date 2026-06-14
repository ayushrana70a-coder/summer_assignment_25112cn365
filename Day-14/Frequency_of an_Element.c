#include <stdio.h>

int main() {
    int size, target, count = 0;

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

    // 3. Get the element whose frequency needs to be counted
    printf("\nEnter the element to find its frequency: ");
    scanf("%d", &target);

    // 4. Count the frequency
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++; // Increment count every time the target is found
        }
    }

    // 5. Display the result
    printf("The element %d appears %d time(s) in the array.\n", target, count);

    return 0;
}