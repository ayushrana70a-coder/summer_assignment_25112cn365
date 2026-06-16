#include <stdio.h>

int main() {
    int n;

    // 1. Get the value of 'n' (the maximum number in the range)
    printf("Enter the value of n (total range 1 to n): ");
    scanf("%d", &n);

    // The array will have (n - 1) elements because one is missing
    int total_elements = n - 1;
    int arr[total_elements];

    // 2. Get the array elements from the user
    printf("Enter %d elements (between 1 and %d with one missing):\n", total_elements, n);
    for (int i = 0; i < total_elements; i++) {
        scanf("%d", &arr[i]);
    }

    // --- FIND MISSING NUMBER LOGIC START ---

    // Step A: Calculate the sum of first n natural numbers
    int expected_sum = (n * (n + 1)) / 2;

    // Step B: Calculate the actual sum of elements in the array
    int actual_sum = 0;
    for (int i = 0; i < total_elements; i++) {
        actual_sum += arr[i];
    }

    // Step C: The missing number is the difference
    int missing_number = expected_sum - actual_sum;

    // --- FIND MISSING NUMBER LOGIC END ---

    // 3. Print the result
    printf("The missing number is: %d\n", missing_number);

    return 0;
}