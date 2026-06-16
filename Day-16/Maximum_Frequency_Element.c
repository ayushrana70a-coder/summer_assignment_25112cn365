#include <stdio.h>

int main() {
    int n;

    // 1. Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // 2. Get the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // --- FIND MAXIMUM FREQUENCY LOGIC START ---

    int max_element = arr[0]; // Stores the element with the highest frequency
    int max_count = 0;       // Stores the highest frequency count found

    for (int i = 0; i < n; i++) {
        int current_element = arr[i];
        int current_count = 0;

        // Count how many times current_element appears in the whole array
        for (int j = 0; j < n; j++) {
            if (arr[j] == current_element) {
                current_count++;
            }
        }

        // If the current element's frequency is higher than max_count, update it
        if (current_count > max_count) {
            max_count = current_count;
            max_element = current_element;
        }
    }

    // --- FIND MAXIMUM FREQUENCY LOGIC END ---

    // 3. Print the result
    printf("The maximum frequency element is: %d (appears %d times)\n", max_element, max_count);

    return 0;
}