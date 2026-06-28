#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LIMIT 50
#define DEPT_LIMIT 30

// Structure definition to store an individual employee record
typedef struct {
    int id;
    char name[NAME_LIMIT];
    char department[DEPT_LIMIT];
    double salary;
} Employee;

// Function Prototypes
void addEmployee(Employee roster[], int *count);
void displayRoster(Employee roster[], int count);
void searchEmployee(Employee roster[], int count);
void filterByDepartment(Employee roster[], int count);
void calculatePayroll(Employee roster[], int count);
int findEmployeeIndexById(Employee roster[], int count, int id);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    Employee roster[MAX_EMPLOYEES];
    int count = 0; // Tracks the current active number of employees in the system
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n     EMPLOYEE MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Filter Employees by Department");
        printf("\n5. Calculate Total Payroll Costs");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(roster, &count); break;
            case 2: displayRoster(roster, count); break;
            case 3: searchEmployee(roster, count); break;
            case 4: filterByDepartment(roster, count); break;
            case 5: calculatePayroll(roster, count); break;
            case 6: 
                printf("\nShutting down Employee Management Database. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select a valid option from the menu.\n");
        }
    }
}

// Helper Function: Linear search utility based on structural Employee ID matching
int findEmployeeIndexById(Employee roster[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (roster[i].id == id) {
            return i; // Returns internal index slot reference matching target ID
        }
    }
    return -1; // ID not found
}

// 1. Add Employee Record with unique ID validation guards
void addEmployee(Employee roster[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nDatabase Error: Storage capacity reached (%d max)!\n", MAX_EMPLOYEES);
        return;
    }

    int tempId;
    printf("\nEnter Unique Employee ID (Integer): ");
    scanf("%d", &tempId);

    // Business Logic Validation: Ensure Employee IDs act as singular unique keys
    if (findEmployeeIndexById(roster, *count, tempId) != -1) {
        printf("\nError: An employee with ID %d already exists! Record registration aborted.\n", tempId);
        return;
    }

    roster[*count].id = tempId;

    printf("Enter Employee Full Name: ");
    getchar(); // Flush dangling trailing newline from stream parsing buffers
    fgets(roster[*count].name, NAME_LIMIT, stdin);
    roster[*count].name[strcspn(roster[*count].name, "\n")] = '\0'; // Strip newline character cleanly

    printf("Enter Department: ");
    fgets(roster[*count].department, DEPT_LIMIT, stdin);
    roster[*count].department[strcspn(roster[*count].department, "\n")] = '\0';

    printf("Enter Monthly Salary: ");
    scanf("%lf", &roster[*count].salary);
    
    // Bounds enforcement loop for negative salaries
    while (roster[*count].salary < 0.0) {
        printf("Invalid entry! Salary cannot be negative. Re-enter: ");
        scanf("%lf", &roster[*count].salary);
    }

    (*count)++; // Scale global database size tracker upward
    printf("\nSuccess: Employee profile successfully registered!\n");
}

// 2. Output All Formatted Database Rows
void displayRoster(Employee roster[], int count) {
    if (count == 0) {
        printf("\nNo employee records logged in the system currently.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-10s %-30s %-20s %-15s\n", "Emp ID", "Employee Name", "Department", "Salary");
    printf--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-20s $%-14.2f\n", 
               roster[i].id, 
               roster[i].name, 
               roster[i].department, 
               roster[i].salary);
    }
    printf("--------------------------------------------------------------------------------\n");
}

// 3. Pinpoint a specific structural record matching an ID key
void searchEmployee(Employee roster[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. Nothing to search.\n");
        return;
    }

    int targetId;
    printf("\nEnter Employee ID to look up: ");
    scanf("%d", &targetId);

    int index = findEmployeeIndexById(roster, count, targetId);

    if (index == -1) {
        printf("\nRecord Match Failed: No profile found for Employee ID %d.\n", targetId);
    } else {
        printf("\n--- Employee Profile Located ---");
        printf("\nID:         %d", roster[index].id);
        printf("\nFull Name:  %s", roster[index].name);
        printf("\nDepartment: %s", roster[index].department);
        printf("\nSalary:     $%.2f per month\n", roster[index].salary);
    }
}

// 4. Sub-catalog isolation: Fetch subset matching string keys across a department category
void filterByDepartment(Employee roster[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    char targetDept[DEPT_LIMIT];
    printf("\nEnter Department Name to filter: ");
    getchar(); // Clean out trailing stream residue characters
    fgets(targetDept, DEPT_LIMIT, stdin);
    targetDept[strcspn(targetDept, "\n")] = '\0';

    int matchesFound = 0;
    printf("\n--- Employees in \"%s\" Department ---\n", targetDept);
    printf("%-10s %-30s %-15s\n", "Emp ID", "Employee Name", "Salary");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        // Checking case-sensitive matches using direct string comparison techniques
        if (strcmp(roster[i].department, targetDept) == 0) {
            printf("%-10d %-30s $%-14.2f\n", roster[i].id, roster[i].name, roster[i].salary);
            matchesFound++;
        }
    }

    if (matchesFound == 0) {
        printf("No records found matching department \"%s\" inside the current database.\n", targetDept);
    }
}

// 5. Financial Audit: Compute absolute valuations of financial payroll metrics
void calculatePayroll(Employee roster[], int count) {
    if (count == 0) {
        printf("\nPayroll metrics cannot be generated with an empty database.\n");
        return;
    }

    double totalPayroll = 0.0;
    for (int i = 0; i < count; i++) {
        totalPayroll += roster[i].salary;
    }

    double averageSalary = totalPayroll / count;

    printf("\n================================================");
    printf("\n          FINANCIAL PAYROLL ANALYSIS            ");
    printf("\n================================================");
    printf("\nTotal Active Staff:             %d", count);
    printf("\nTotal Monthly Payroll Cost:    **$%.2f**", totalPayroll);
    printf("\nAverage Employee Salary:        **$%.2f**", averageSalary);
    printf("\n================================================\n");
}