#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Define the employee structure
typedef struct {
    int empId;
    char name[50];
    char department[40];
    char designation[40];
    float salary;
} Employee;

// Function Prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM ");
        printf("\n====================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Employee");
        printf("\n4. Update Employee Details");
        printf("\n5. Remove Employee Record");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting system. Have a great day!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
}

// 1. Add an employee record to the file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Append-binary mode
    if (fp == NULL) {
        printf("\nError opening database file!");
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.empId);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = 0; // Strip newline character

    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(e.designation, sizeof(e.designation), stdin);
    e.designation[strcspn(e.designation, "\n")] = 0;

    printf("Enter Monthly Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("\nEmployee record saved successfully!\n");
}

// 2. Read and format all employee records
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Read-binary mode
    if (fp == NULL) {
        printf("\nNo database found. Please add a record first!\n");
        return;
    }

    Employee e;
    printf("\n---------------------------------------------------------------------------------");
    printf("\n%-8s %-22s %-15s %-18s %-12s", "ID", "Name", "Department", "Designation", "Salary");
    printf("\n---------------------------------------------------------------------------------");

    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        printf("\n%-8d %-22s %-15s %-18s $%-11.2f", e.empId, e.name, e.department, e.designation, e.salary);
    }
    printf("\n---------------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for an employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo employee database records exist.\n");
        return;
    }

    int targetId, found = 0;
    Employee e;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &targetId);

    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.empId == targetId) {
            found = 1;
            printf("\n--- Record Found ---");
            printf("\nID:          %d", e.empId);
            printf("\nName:        %s", e.name);
            printf("\nDepartment:  %s", e.department);
            printf("\nDesignation: %s", e.designation);
            printf("\nSalary:      $%.2f\n", e.salary);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}

// 4. Update employee data in-place
void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Read/Write binary mode
    if (fp == NULL) {
        printf("\nNo employee database records exist.\n");
        return;
    }

    int targetId, found = 0;
    Employee e;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &targetId);

    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.empId == targetId) {
            found = 1;
            getchar(); // Clear buffer

            printf("\nEnter New Name: ");
            fgets(e.name, sizeof(e.name), stdin);
            e.name[strcspn(e.name, "\n")] = 0;

            printf("Enter New Department: ");
            fgets(e.department, sizeof(e.department), stdin);
            e.department[strcspn(e.department, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(e.designation, sizeof(e.designation), stdin);
            e.designation[strcspn(e.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &e.salary);

            // Move pointer back to overwrite this exact struct
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&e, sizeof(Employee), 1, fp);
            printf("\nEmployee details updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}

// 5. Delete a record using a shadow/temp file approach
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo employee database records exist.\n");
        return;
    }

    FILE *tempFp = fopen("temp_emp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nCritical error creating safe scratch file!");
        fclose(fp);
        return;
    }

    int targetId, found = 0;
    Employee e;

    printf("\nEnter Employee ID to remove: ");
    scanf("%d", &targetId);

    // Filter out the target record
    while (fread(&e, sizeof(Employee), 1, fp) == 1) {
        if (e.empId == targetId) {
            found = 1;
        } else {
            fwrite(&e, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);
        rename("temp_emp.dat", FILE_NAME);
        printf("\nEmployee record purged from system.\n");
    } else {
        remove("temp_emp.dat"); // Delete unused temp file
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
}