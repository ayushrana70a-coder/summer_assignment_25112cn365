#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LENGTH 40

// Structure definition to bundle inventory item attributes
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Item;

// Function Prototypes
void addItem(Item inventory[], int *count);
void displayInventory(Item inventory[], int count);
void searchItem(Item inventory[], int count);
void updateStock(Item inventory[], int count);
void calculateTotalValue(Item inventory[], int count);
int findItemIndexById(Item inventory[], int count, int id);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    Item inventory[MAX_ITEMS];
    int count = 0; // Active tracker for the number of items stored in inventory
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     INVENTORY MANAGEMENT SYSTEM    ");
        printf("\n====================================");
        printf("\n1. Add New Item");
        printf("\n2. Display Full Inventory");
        printf("\n3. Search for an Item");
        printf("\n4. Update Item Stock (Restock/Sell)");
        printf("\n5. Calculate Total Inventory Value");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addItem(inventory, &count); 
                break;
            case 2: 
                displayInventory(inventory, count); 
                break;
            case 3: 
                searchItem(inventory, count); 
                break;
            case 4: 
                updateStock(inventory, count); 
                break;
            case 5: 
                calculateTotalValue(inventory, count); 
                break;
            case 6: 
                printf("\nShutting down Inventory System. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select a valid option from the menu.\n");
        }
    }
}

// Helper function: Returns array index matching a specific ID, or -1 if not found
int findItemIndexById(Item inventory[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            return i; // Found matching reference index
        }
    }
    return -1; // No match found
}

// 1. Add New Item (With inventory capacity and duplicate ID validation)
void addItem(Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("\nError: Inventory capacity reached! Cannot add more items.\n");
        return;
    }

    int tempId;
    printf("\nEnter Unique Item ID (Integer): ");
    scanf("%d", &tempId);

    // Business Logic Rule: IDs must be unique
    if (findItemIndexById(inventory, *count, tempId) != -1) {
        printf("\nError: An item with ID %d already exists! Operation aborted.\n", tempId);
        return;
    }

    inventory[*count].id = tempId;

    printf("Enter Item Name: ");
    getchar(); // Flush remaining newline buffer
    fgets(inventory[*count].name, NAME_LENGTH, stdin);
    inventory[*count].name[strcspn(inventory[*count].name, "\n")] = '\0'; // Strip newline character

    printf("Enter Initial Quantity: ");
    scanf("%d", &inventory[*count].quantity);
    
    printf("Enter Unit Price: ");
    scanf("%lf", &inventory[*count].price);

    (*count)++; // Increment system-wide database size tracker
    printf("\nSuccess: Item added to inventory tracking database!\n");
}

// 2. Display Full Inventory System Grid
void displayInventory(Item inventory[], int count) {
    if (count == 0) {
        printf("\nYour inventory is completely empty!\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-12s\n", "Item ID", "Item Name", "Quantity", "Price");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-12d $%-11.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("-----------------------------------------------------------------\n");
}

// 3. Search for an Item
void searchItem(Item inventory[], int count) {
    if (count == 0) {
        printf("\nInventory empty. Nothing to search.\n");
        return;
    }

    int targetId;
    printf("\nEnter Item ID to look up: ");
    scanf("%d", &targetId);

    int index = findItemIndexById(inventory, count, targetId);

    if (index == -1) {
        printf("\nItem Profile Match with ID %d not found.\n", targetId);
    } else {
        printf("\n--- Item Record Located ---");
        printf("\nID:       %d", inventory[index].id);
        printf("\nName:     %s", inventory[index].name);
        printf("\nStock:    %d units", inventory[index].quantity);
        printf("\nPrice:    $%.2f each\n", inventory[index].price);
    }
}

// 4. Update Stock Quantity Level (Add restock or subtract sales)
void updateStock(Item inventory[], int count) {
    if (count == 0) {
        printf("\nInventory empty. No stock values to edit.\n");
        return;
    }

    int targetId;
    printf("\nEnter Item ID to modify stock levels: ");
    scanf("%d", &targetId);

    int index = findItemIndexById(inventory, count, targetId);

    if (index == -1) {
        printf("\nError: Item ID %d does not exist.\n", targetId);
        return;
    }

    int stockUpdateChoice, updateAmount;
    printf("\nCurrent Stock: %d units for \"%s\".", inventory[index].quantity, inventory[index].name);
    printf("\n1. Restock (Add items)\n2. Dispatch/Sell (Subtract items)\nSelect Action (1-2): ");
    scanf("%d", &stockUpdateChoice);

    if (stockUpdateChoice == 1) {
        printf("Enter quantity to add: ");
        scanf("%d", &updateAmount);
        inventory[index].quantity += updateAmount;
        printf("\nStock updated! New Quantity: %d\n", inventory[index].quantity);
    } else if (stockUpdateChoice == 2) {
        printf("Enter quantity to subtract: ");
        scanf("%d", &updateAmount);
        
        // Business Logic Validation: Prevent negative stock levels
        if (updateAmount > inventory[index].quantity) {
            printf("\nTransaction Error: Deficient Stock level! You only have %d units.\n", inventory[index].quantity);
        } else {
            inventory[index].quantity -= updateAmount;
            printf("\nTransaction Finalized! New Quantity Remaining: %d\n", inventory[index].quantity);
        }
    } else {
        printf("\nInvalid Selection. Aborting update operation.\n");
    }
}

// 5. Financial Audit: Compute absolute valuations of assets inside storage structures
void calculateTotalValue(Item inventory[], int count) {
    if (count == 0) {
        printf("\nInventory empty. Valuation assets hold a raw balance score of $0.00\n");
        return;
    }

    double grandTotal = 0.0;
    for (int i = 0; i < count; i++) {
        grandTotal += (inventory[i].quantity * inventory[i].price);
    }

    printf("\n================================================");
    printf("\n  Total Financial Valuation: **$%.2f**", grandTotal);
    printf("\n  Total Unique Product Profiles: %d", count);
    printf("\n================================================\n");
}