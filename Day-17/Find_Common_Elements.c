#include <stdio.h>

int main() {
    int n1, n2;

    // 1. Input for the First Array
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 2. Input for the Second Array
    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- FIND COMMON ELEMENTS LOGIC START ---

    // Create an array to hold the common elements found
    int commonArr[n1 < n2 ? n1 : n2];
    int common_count = 0;

    // Check each element of arr1
    for (int i = 0; i < n1; i++) {
        int exists_in_second = 0;

        // Look for a match in arr2
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                exists_in_second = 1;
                break;
            }
        }

        // If it exists in both, make sure we haven't already saved it before
        if (exists_in_second == 1) {
            int already_saved = 0;
            for (int k = 0; k < common_count; k++) {
                if (arr1[i] == commonArr[k]) {
                    already_saved = 1;
                    break;
                }
            }

            // If it's a new common element, save it
            if (already_saved == 0) {
                commonArr[common_count] = arr1[i];
                common_count++;
            }
        }
    }

    // --- FIND COMMON ELEMENTS LOGIC END ---

    // 3. Print the results
    printf("Common elements are: ");
    if (common_count == 0) {
        printf("None");
    } else {
        for (int i = 0; i < common_count; i++) {
            printf("%d ", commonArr[i]);
        }
    }
    printf("\n");

    return 0;
}