#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LIMIT 60
#define AUTHOR_LIMIT 40
#define ACC_LIMIT 15

// Structure definition to store an individual book record
typedef struct {
    char accessionNumber[ACC_LIMIT];
    char title[TITLE_LIMIT];
    char author[AUTHOR_LIMIT];
    int isIssued; // 0 = Available, 1 = Checked Out/Issued
} Book;

// Function Prototypes
void addBook(Book library[], int *count);
void displayCatalog(Book library[], int count);
void searchByAccNo(Book library[], int count);
void listBooksByAuthor(Book library[], int count);
void toggleIssueStatus(Book library[], int count, int actionType);
int findBookIndexByAccNo(Book library[], int count, const char accNo[]);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    Book library[MAX_BOOKS];
    int count = 0; // Tracks the current active number of books inside the catalog
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n        MINI LIBRARY SYSTEM         ");
        printf("\n====================================");
        printf("\n1. Add New Book Record");
        printf("\n2. Display Full Book Catalog");
        printf("\n3. Search Book by Accession Number");
        printf("\n4. List All Books by Specific Author");
        printf("\n5. Issue / Check-out a Book");
        printf("\n6. Return / Check-in a Book");
        printf("\n7. Exit");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(library, &count); break;
            case 2: displayCatalog(library, count); break;
            case 3: searchByAccNo(library, count); break;
            case 4: listBooksByAuthor(library, count); break;
            case 5: toggleIssueStatus(library, count, 1); break; // 1 for Issue
            case 6: toggleIssueStatus(library, count, 0); break; // 0 for Return
            case 7: 
                printf("\nClosing library system catalog registry. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please enter a valid menu option.\n");
        }
    }
}

// Helper Function: Linear search utility based on structural Accession Number matching
int findBookIndexByAccNo(Book library[], int count, const char accNo[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].accessionNumber, accNo) == 0) {
            return i; // Returns internal index slot reference matching target string
        }
    }
    return -1; // Unique identifier sequence not found
}

// 1. Add Book Profile with unique sequence checking safeguards
void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nCatalog Error: Storage limit reached! Cannot catalog more books.\n");
        return;
    }

    char tempAcc[ACC_LIMIT];
    printf("\nEnter Unique Accession Number (e.g., ACC102): ");
    scanf("%s", tempAcc);

    // Business Logic Validation Rule: Accession tags must serve as singular unique keys
    if (findBookIndexByAccNo(library, *count, tempAcc) != -1) {
        printf("\nDatabase Error: A book with Accession Number \"%s\" is already cataloged!\n", tempAcc);
        return;
    }

    strcpy(library[*count].accessionNumber, tempAcc);

    printf("Enter Book Title: ");
    getchar(); // Flush dangling trailing newline from stream parsing buffers
    fgets(library[*count].title, TITLE_LIMIT, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0'; // Remove clean newline wrap

    printf("Enter Author Name: ");
    fgets(library[*count].author, AUTHOR_LIMIT, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = '\0';

    library[*count].isIssued = 0; // Default: Book is available inside shelves upon inventory onboarding

    (*count)++; // Scale global archive catalog footprints upward
    printf("\nSuccess: Book successfully indexed inside the library catalog!\n");
}

// 2. Display complete tracking log spreadsheet
void displayCatalog(Book library[], int count) {
    if (count == 0) {
        printf("\nThe library catalog registry is currently completely empty.\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("%-15s %-35s %-22s %-12s\n", "Accession No", "Book Title", "Author", "Availability");
    printf("---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-35s %-22s %-12s\n", 
               library[i].accessionNumber, 
               library[i].title, 
               library[i].author, 
               (library[i].isIssued == 1) ? "Issued" : "Available");
    }
    printf("---------------------------------------------------------------------------------------\n");
}

// 3. Pinpoint a specific structural book map matching a particular target key
void searchByAccNo(Book library[], int count) {
    if (count == 0) {
        printf("\nLibrary archive is empty. Nothing to search.\n");
        return;
    }

    char targetAcc[ACC_LIMIT];
    printf("\nEnter the book Accession Number to find: ");
    scanf("%s", targetAcc);

    int index = findBookIndexByAccNo(library, count, targetAcc);

    if (index == -1) {
        printf("\nResult: No book record matches Accession Number \"%s\".\n", targetAcc);
    } else {
        printf("\n--- Book Profile Located ---");
        printf("\nAccession No: %s", library[index].accessionNumber);
        printf("\nTitle:        %s", library[index].title);
        printf("\nAuthor:       %s", library[index].author);
        printf("\nStatus:       [%s]\n", (library[index].isIssued == 1) ? "Currently Checked Out" : "Available on Shelves");
    }
}

// 4. Sub-catalog isolation: Fetch subset matching string keys across matching Author categories
void listBooksByAuthor(Book library[], int count) {
    if (count == 0) {
        printf("\nLibrary archive is empty.\n");
        return;
    }

    char targetAuthor[AUTHOR_LIMIT];
    printf("\nEnter Author Name to filter: ");
    getchar(); // Clean out trailing stream residue strings
    fgets(targetAuthor, AUTHOR_LIMIT, stdin);
    targetAuthor[strcspn(targetAuthor, "\n")] = '\0';

    int matchesFound = 0;
    printf("\n--- Books authored by \"%s\" ---\n", targetAuthor);
    for (int i = 0; i < count; i++) {
        // Checking case-sensitive matches using direct string comparison techniques
        if (strcmp(library[i].author, targetAuthor) == 0) {
            printf("- [%s] %s (%s)\n", library[i].accessionNumber, library[i].title, 
                   (library[i].isIssued == 1) ? "Issued" : "Available");
            matchesFound++;
        }
    }

    if (matchesFound == 0) {
        printf("No books found matching author \"%s\" inside the current active catalogs.\n", targetAuthor);
    }
}

// 5 & 6. Transaction Engine: Unified transactional router swapping states safely
void toggleIssueStatus(Book library[], int count, int actionType) {
    if (count == 0) {
        printf("\nLibrary collection is empty. Transactions cannot process.\n");
        return;
    }

    char targetAcc[ACC_LIMIT];
    printf("\nEnter Book Accession Number for verification: ");
    scanf("%s", targetAcc);

    int index = findBookIndexByAccNo(library, count, targetAcc);

    if (index == -1) {
        printf("\nError: Accession Number \"%s\" does not match any items in stock.\n", targetAcc);
        return;
    }

    if (actionType == 1) { // Process a Check-out request
        if (library[index].isIssued == 1) {
            printf("\nTransaction Aborted: \"%s\" is already checked out to another patron.\n", library[index].title);
        } else {
            library[index].isIssued = 1;
            printf("\nSuccess: \"%s\" has been checked out successfully.\n", library[index].title);
        }
    } else if (actionType == 0) { // Process a Check-in / Return request
        if (library[index].isIssued == 0) {
            printf("\nTransaction Warning: \"%s\" is already present on the display shelves.\n", library[index].title);
        } else {
            library[index].isIssued = 0;
            printf("\nSuccess: Thank you! \"%s\" has been checked in safely.\n", library[index].title);
        }
    }
}