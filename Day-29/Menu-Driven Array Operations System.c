#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum storage capacity of the array

// Function Prototypes
void display(int arr[], int size);
int insertElement(int arr[], int size);
int deleteElement(int arr[], int size);
void searchElement(int arr[], int size);
void sortArray(int arr[], int size);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int arr[MAX_SIZE];
    int size = 0; // Tracks the current active number of elements in the array
    int choice;

    // Optional initial setup
    printf("Enter the initial number of elements (0 to %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > 0 && size <= MAX_SIZE) {
        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    } else {
        size = 0; // Fallback to empty if invalid configuration entered
    }

    while (1) {
        printf("\n====================================");
        printf("\n       ARRAY OPERATIONS SYSTEM      ");
        printf("\n====================================");
        printf("\n1. Display Array");
        printf("\n2. Insert an Element");
        printf("\n3. Delete an Element");
        printf("\n4. Search for an Element");
        printf("\n5. Sort the Array (Bubble Sort)");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                display(arr, size); 
                break;
            case 2: 
                size = insertElement(arr, size); 
                break;
            case 3: 
                size = deleteElement(arr, size); 
                break;
            case 4: 
                searchElement(arr, size); 
                break;
            case 5: 
                sortArray(arr, size); 
                break;
            case 6: 
                printf("\nExiting System. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// 1. Traverse and display the current state of the array
void display(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is currently empty!\n");
        return;
    }
    printf("\nCurrent Array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\nTotal Elements: %d\n", size);
}

// 2. Insert an element at a specific index location (with overflow protection)
int insertElement(int arr[], int size) {
    if (size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return size;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position index (0 to %d): ", size);
    scanf("%d", &position);

    // Validation check for array positioning boundaries
    if (position < 0 || position > size) {
        printf("\nInvalid position! Position must be between 0 and %d.\n", size);
        return size;
    }

    // Shift elements to the right to make room for the new value
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    printf("\nElement %d successfully inserted at index %d!\n", element, position);
    return size + 1; // Increment current active tracker
}

// 3. Delete an element from a specific index location (with underflow protection)
int deleteElement(int arr[], int size) {
    if (size == 0) {
        printf("\nError: Array Underflow! No elements available to delete.\n");
        return size;
    }

    int position;
    printf("\nEnter the index position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("\nInvalid position index entered!\n");
        return size;
    }

    int deletedValue = arr[position];

    // Shift elements left to plug the gap left by the deleted item
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("\nElement %d removed from index %d successfully.\n", deletedValue, position);
    return size - 1; // Decrement current active tracker
}

// 4. Linear search implementation
void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty. Nothing to search.\n");
        return;
    }

    int target, found = 0;
    printf("\nEnter target element value to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found! Target match **%d** located at array index: %d\n", target, i);
            found = 1;
        }
    }

    if (!found) {
        printf("Element %d not found anywhere inside the array matrix.\n", target);
    }
}

// 5. In-place Bubble Sort optimization
void sortArray(int arr[], int size) {
    if (size <= 1) {
        printf("\nArray requires at least 2 elements to carry out a sort routing.\n");
        return;
    }

    // Bubble Sort implementation
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Classic standard value swap routine
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // Optimization: If no swapping took place, the structure is already ordered
        if (swapped == 0) break;
    }
    printf("\nArray successfully sorted in Ascending Order!\n");
}