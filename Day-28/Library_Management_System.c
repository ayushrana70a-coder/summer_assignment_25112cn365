#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "books.dat"

// Define the Book structure
typedef struct {
    int bookId;
    char title[50];
    char author[50];
    int totalCopies;
    int issuedCopies;
} Book;

// Function Prototypes
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n     LIBRARY MANAGEMENT SYSTEM      ");
        printf("\n====================================");
        printf("\n1. Add New Book to Catalog");
        printf("\n2. Display Complete Catalog");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("\nExiting system. Happy reading!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
}

// 1. Add a new book or initial stock to the database
void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError opening catalog file!");
        return;
    }

    Book b;
    printf("\nEnter Unique Book ID: ");
    scanf("%d", &b.bookId);
    getchar(); // Clean trailing newline from input buffer

    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0; // Strip newline

    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;

    printf("Enter Total Copies to Add: ");
    scanf("%d", &b.totalCopies);
    b.issuedCopies = 0; // Freshly added books start with zero active loans

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);

    printf("\nBook successfully registered to catalog!\n");
}

// 2. Read and print a formatted summary of all inventory
void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo catalog records found. Add some books first!\n");
        return;
    }

    Book b;
    printf("\n----------------------------------------------------------------------------------");
    printf("\n%-8s %-25s %-20s %-12s %-12s", "ID", "Title", "Author", "Total Stock", "Available");
    printf("\n----------------------------------------------------------------------------------");

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        int available = b.totalCopies - b.issuedCopies;
        printf("\n%-8d %-25s %-20s %-12d %-12d", b.bookId, b.title, b.author, b.totalCopies, available);
    }
    printf("\n----------------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search catalog by Book ID, Title, or Author
void searchBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nThe catalog is currently empty.\n");
        return;
    }

    int choice, targetId, found = 0;
    char targetStr[50];
    Book b;

    printf("\nSearch Options:");
    printf("\n1. Search by Book ID");
    printf("\n2. Search by Title or Author keyword");
    printf("\nEnter your choice (1-2): ");
    scanf("%d", &choice);
    getchar(); // Clear buffer

    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &targetId);
    } else {
        printf("Enter Search Term (Title or Author): ");
        fgets(targetStr, sizeof(targetStr), stdin);
        targetStr[strcspn(targetStr, "\n")] = 0;
    }

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        // Evaluate conditions based on choice
        if ((choice == 1 && b.bookId == targetId) || 
            (choice != 1 && (strstr(b.title, targetStr) != NULL || strstr(b.author, targetStr) != NULL))) {
            
            if (!found) printf("\n%-8s %-25s %-20s %-12s", "ID", "Title", "Author", "Available");
            found = 1;
            printf("\n%-8d %-25s %-20s %-12d", b.bookId, b.title, b.author, (b.totalCopies - b.issuedCopies));
        }
    }

    if (!found) {
        printf("\nNo matching books found in the registry.\n");
    }
    printf("\n");
    fclose(fp);
}

// 4. Update ledger allocation to borrow a copy
void issueBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nCatalog is inaccessible.\n");
        return;
    }

    int targetId, found = 0;
    Book b;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &targetId);

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.bookId == targetId) {
            found = 1;
            
            // Validation: Check if there's copy overhead left
            if (b.issuedCopies < b.totalCopies) {
                b.issuedCopies++;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("\nSuccess! '%s' has been checked out.\n", b.title);
            } else {
                printf("\nSorry, all copies of this book are currently checked out!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d not found in system.\n", targetId);
    }
    fclose(fp);
}

// 5. Update ledger allocation to return a copy
void returnBook() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nCatalog is inaccessible.\n");
        return;
    }

    int targetId, found = 0;
    Book b;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &targetId);

    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (b.bookId == targetId) {
            found = 1;
            
            // Validation: Check if copies were actually checked out
            if (b.issuedCopies > 0) {
                b.issuedCopies--;
                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);
                printf("\nSuccess! '%s' has been returned to stock.\n", b.title);
            } else {
                printf("\nError: Ledger records indicate all copies of this book are already in inventory.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook ID %d not found in system.\n", targetId);
    }
    fclose(fp);
}