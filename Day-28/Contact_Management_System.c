#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

// Define the Contact structure
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function Prototypes
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void deleteContact();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n      CONTACT MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add New Contact");
        printf("\n2. Display All Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Update Contact Details");
        printf("\n5. Delete Contact");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("\nExiting Phonebook. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }
}

// 1. Add a new contact into the file ledger
void addContact() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("\nError opening address book storage file!");
        return;
    }

    Contact c;
    getchar(); // Clear any trailing newline buffer character

    printf("\nEnter Contact Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email Address: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);

    printf("\nContact for '%s' saved successfully!\n", c.name);
}

// 2. Read and view the complete contact list
void displayContacts() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo contact records found. Create one first!\n");
        return;
    }

    Contact c;
    printf("\n--------------------------------------------------------------------------------");
    printf("\n%-25s %-20s %-30s", "Name", "Phone Number", "Email Address");
    printf("\n--------------------------------------------------------------------------------");

    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        printf("\n%-25s %-20s %-30s", c.name, c.phone, c.email);
    }
    printf("\n--------------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search contact book using a partial keyword or number query fragment
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nYour phonebook directory is completely empty.\n");
        return;
    }

    char query[50];
    int found = 0;
    getchar(); // Clear buffer

    printf("\nEnter Name or Phone Number keyword to search: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0;

    Contact c;
    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        // Partial string lookup using strstr
        if (strstr(c.name, query) != NULL || strstr(c.phone, query) != NULL) {
            if (!found) {
                printf("\n--- Matching Search Results ---");
            }
            found = 1;
            printf("\nName  : %s", c.name);
            printf("\nPhone : %s", c.phone);
            printf("\nEmail : %s", c.email);
            printf("\n--------------------------------");
        }
    }

    if (!found) {
        printf("\nNo contacts found matching the term '%s'.\n", query);
    }
    fclose(fp);
}

// 4. Locate a contact profile and overwrite structural fields in-place
void updateContact() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Read/Write binary mode
    if (fp == NULL) {
        printf("\nNo address book database records exist.\n");
        return;
    }

    char targetName[50];
    int found = 0;
    getchar(); // Clear buffer

    printf("\nEnter exact Contact Name to modify: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = 0;

    Contact c;
    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcmp(c.name, targetName) == 0) {
            found = 1;

            printf("\n--- Current Details found for %s ---", c.name);
            printf("\nEnter New Phone Number: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            printf("Enter New Email Address: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = 0;

            // Roll back the file stream position pointer by one struct dimension footprint
            fseek(fp, -sizeof(Contact), SEEK_CUR);
            fwrite(&c, sizeof(Contact), 1, fp);
            
            printf("\nContact update processed cleanly!\n");
            break;
        }
    }

    if (!found) {
        printf("\nContact matching name '%s' was not found.\n", targetName);
    }
    fclose(fp);
}

// 5. Purge structural element out of the system file footprint completely
void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo contact database records exist.\n");
        return;
    }

    FILE *tempFp = fopen("temp_contacts.dat", "wb");
    if (tempFp == NULL) {
        printf("\nCritical internal file creation block mapping failure!");
        fclose(fp);
        return;
    }

    char targetName[50];
    int found = 0;
    getchar(); // Clear buffer

    printf("\nEnter Name of the Contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = 0;

    Contact c;
    // Copy all data segments except the targeted element over to a scratch pad ledger
    while (fread(&c, sizeof(Contact), 1, fp) == 1) {
        if (strcmp(c.name, targetName) == 0) {
            found = 1;
        } else {
            fwrite(&c, sizeof(Contact), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);                  // Clear primary footprint
        rename("temp_contacts.dat", FILE_NAME); // Swap temp into production spot
        printf("\nContact entry for '%s' was deleted permanently.\n", targetName);
    } else {
        remove("temp_contacts.dat"); // Delete structural scrap remnant
        printf("\nContact matching name '%s' was not found.\n", targetName);
    }
}