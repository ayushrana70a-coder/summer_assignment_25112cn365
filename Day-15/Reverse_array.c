#include <stdio.h>

int main() {
    int size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size]; 

    // 2. Take array elements as input from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Print the array in reverse order
    printf("\nReversed array is:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}