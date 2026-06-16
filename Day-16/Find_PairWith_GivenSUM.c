#include <stdio.h>

int main() {
    int n, target_sum;
    int found = 0; // A flag to check if we found a pair

    // 1. Get the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // 2. Get the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Get the target sum
    printf("Enter the target sum you want to find: ");
    scanf("%d", &target_sum);

    // --- FIND PAIR LOGIC START ---

    // Outer loop selects the first element of the pair
    for (int i = 0; i < n - 1; i++) {
        
        // Inner loop selects the second element of the pair
        for (int j = i + 1; j < n; j++) {
            
            // Check if the sum of the two elements matches the target
            if (arr[i] + arr[j] == target_sum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1; // Mark that we found at least one pair
                break;     // Break inner loop if you only want one unique pair for this 'i'
            }
        }
        
        // Optional: Remove the comment below if you want to stop entirely after finding the FIRST pair
        // if (found) break; 
    }

    // If no pair was found after checking everything
    if (found == 0) {
        printf("No pair found with the given sum.\n");
    }

    // --- FIND PAIR LOGIC END ---

    return 0;
}