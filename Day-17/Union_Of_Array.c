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

    // --- UNION LOGIC START ---

    // Create an array large enough to hold the worst-case size (n1 + n2)
    int unionArr[n1 + n2];
    int union_size = 0;

    // Step A: Add all elements of the first array to unionArr (removing internal duplicates)
    for (int i = 0; i < n1; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < union_size; j++) {
            if (arr1[i] == unionArr[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (is_duplicate == 0) {
            unionArr[union_size] = arr1[i];
            union_size++;
        }
    }

    // Step B: Add elements from the second array ONLY if they aren't already in unionArr
    for (int i = 0; i < n2; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < union_size; j++) {
            if (arr2[i] == unionArr[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (is_duplicate == 0) {
            unionArr[union_size] = arr2[i];
            union_size++;
        }
    }

    // --- UNION LOGIC END ---

    // 3. Print the final Union array
    printf("The Union of the two arrays is: ");
    for (int i = 0; i < union_size; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}