#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

// Define the student structure
typedef struct {
    int id;
    char name[50];
    char course[50];
    float gpa;
} Student;

// Function Prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n   STUDENT RECORD MANAGEMENT SYSTEM ");
        printf("\n====================================");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student Record");
        printf("\n4. Update Student Record");
        printf("\n5. Delete Student Record");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// 1. Add a new student record to the file
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    getchar(); // Clear the newline character left in the buffer

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

// 2. Read and display all records
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo records found. Add some students first!\n");
        return;
    }

    Student s;
    printf("\n-------------------------------------------------------------");
    printf("\n%-10s %-25s %-15s %-5s", "ID", "Name", "Course", "GPA");
    printf("\n-------------------------------------------------------------");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("\n%-10d %-25s %-15s %-5.2f", s.id, s.name, s.course, s.gpa);
    }
    printf("\n-------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific student by ID
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int searchId, found = 0;
    Student s;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == searchId) {
            found = 1;
            printf("\nRecord Found:");
            printf("\nID: %d", s.id);
            printf("\nName: %s", s.name);
            printf("\nCourse: %s", s.course);
            printf("\nGPA: %.2f\n", s.gpa);
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Update an existing student record
void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    int updateId, found = 0;
    Student s;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &updateId);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == updateId) {
            found = 1;
            getchar(); // Clear buffer

            printf("\nEnter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;

            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = 0;

            printf("Enter New GPA: ");
            scanf("%f", &s.gpa);

            // Move the file pointer back to the start of this record
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", updateId);
    }
    fclose(fp);
}

// 5. Delete a student record using a temporary file
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found.\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError creating temporary file!");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    Student s;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &deleteId);

    // Copy all records except the one to delete to the temp file
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == deleteId) {
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);             // Delete original file
        rename("temp.dat", FILE_NAME); // Rename temp file to original name
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.dat");            // Clean up temp file if nothing changed
        printf("\nStudent with ID %d not found.\n", deleteId);
    }
}