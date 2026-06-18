#include <stdio.h>

int main() {
    int n1, n2;

    // 1. Input for the First Array
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 2. Input for the Second Array
    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- INTERSECTION LOGIC START ---

    // The intersection size can never be larger than the smaller array
    int intersectArr[n1 < n2 ? n1 : n2];
    int intersect_size = 0;

    // Loop through the first array
    for (int i = 0; i < n1; i++) {
        int found_in_second = 0;

        // Check if arr1[i] exists in the second array
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                found_in_second = 1;
                break;
            }
        }

        // If it exists in the second array, make sure it's not a duplicate in our results
        if (found_in_second == 1) {
            int is_already_added = 0;
            for (int k = 0; k < intersect_size; k++) {
                if (arr1[i] == intersectArr[k]) {
                    is_already_added = 1;
                    break;
                }
            }

            // If it's a brand new common element, add it
            if (is_already_added == 0) {
                intersectArr[intersect_size] = arr1[i];
                intersect_size++;
            }
        }
    }

    // --- INTERSECTION LOGIC END ---

    // 3. Print the final Intersection array
    printf("The Intersection of the two arrays is: ");
    if (intersect_size == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < intersect_size; i++) {
            printf("%d ", intersectArr[i]);
        }
    }
    printf("\n");

    return 0;
}