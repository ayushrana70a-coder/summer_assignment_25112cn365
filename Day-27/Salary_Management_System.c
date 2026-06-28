#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "payroll.dat"

// Define the Payroll structure
typedef struct {
    int empId;
    char name[50];
    char designation[40];
    float basicSalary;
    float hra;             // House Rent Allowance
    float medical;         // Medical Allowance
    float tax;             // Tax Deduction
    float netSalary;       // Calculated Total Net Pay
} Payroll;

// Function Prototypes
void addPayroll();
void displayPayroll();
void searchPayroll();
void updateSalary();
void calculateNetSalary(Payroll *p);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n       SALARY MANAGEMENT SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add Employee Payroll Record");
        printf("\n2. Display Monthly Payroll Slip");
        printf("\n3. Search Employee Pay Record");
        printf("\n4. Modify Salary Components");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPayroll(); break;
            case 2: displayPayroll(); break;
            case 3: searchPayroll(); break;
            case 4: updateSalary(); break;
            case 5: 
                printf("\nExiting Payroll System. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
}

// Helper function to handle math conversions
void calculateNetSalary(Payroll *p) {
    p->netSalary = (p->basicSalary + p->hra + p->medical) - p->tax;
}

// 1. Add employee details and calculate pay components
void addPayroll() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError opening payroll database!");
        return;
    }

    Payroll p;
    printf("\nEnter Employee ID: ");
    scanf("%d", &p.empId);
    getchar(); // Clear newline buffer

    printf("Enter Employee Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(p.designation, sizeof(p.designation), stdin);
    p.designation[strcspn(p.designation, "\n")] = 0;

    printf("Enter Base/Basic Salary: ");
    scanf("%f", &p.basicSalary);

    printf("Enter House Rent Allowance (HRA): ");
    scanf("%f", &p.hra);

    printf("Enter Medical Allowance: ");
    scanf("%f", &p.medical);

    printf("Enter Income Tax Deduction: ");
    scanf("%f", &p.tax);

    // Run processing step
    calculateNetSalary(&p);

    fwrite(&p, sizeof(Payroll), 1, fp);
    fclose(fp);

    printf("\nPayroll record processed and saved successfully!\n");
}

// 2. Read and print a structured layout summary table
void displayPayroll() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo payroll history found. Generate some slips first!\n");
        return;
    }

    Payroll p;
    printf("\n------------------------------------------------------------------------------------------------");
    printf("\n%-6s %-20s %-12s %-10s %-8s %-8s %-8s %-12s", 
           "ID", "Name", "Designation", "Basic", "HRA", "Med.", "Tax", "Net Pay");
    printf("\n------------------------------------------------------------------------------------------------");

    while (fread(&p, sizeof(Payroll), 1, fp) == 1) {
        printf("\n%-6d %-20s %-12s %-10.2f %-8.2f %-8.2f %-8.2f **%-12.2f**", 
               p.empId, p.name, p.designation, p.basicSalary, p.hra, p.medical, p.tax, p.netSalary);
    }
    printf("\n------------------------------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search and generate a detailed itemized break-down slip
void searchPayroll() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nPayroll database is currently empty.\n");
        return;
    }

    int targetId, found = 0;
    Payroll p;

    printf("\nEnter Employee ID to search breakdown: ");
    scanf("%d", &targetId);

    while (fread(&p, sizeof(Payroll), 1, fp) == 1) {
        if (p.empId == targetId) {
            found = 1;
            printf("\n========================================");
            printf("\n         PAYSLIP ITEMIZATION RECORD     ");
            printf("\n========================================");
            printf("\nEmployee ID  : %d", p.empId);
            printf("\nName         : %s", p.name);
            printf("\nDesignation  : %s", p.designation);
            printf("\n----------------------------------------");
            printf("\n(+) Basic Pay           : %.2f", p.basicSalary);
            printf("\n(+) House Rent (HRA)    : %.2f", p.hra);
            printf("\n(+) Medical Benefit     : %.2f", p.medical);
            printf("\n(-) Income Tax Retained : %.2f", p.tax);
            printf("\n----------------------------------------");
            printf("\n(=) TOTAL NET EARNINGS  : %.2f", p.netSalary);
            printf("\n========================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nNo matching record found for Employee ID %d.\n", targetId);
    }
    fclose(fp);
}

// 4. Update figures and recalculate totals automatically
void updateSalary() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo record structures found.\n");
        return;
    }

    int targetId, found = 0;
    Payroll p;

    printf("\nEnter Employee ID to recalculate salary: ");
    scanf("%d", &targetId);

    while (fread(&p, sizeof(Payroll), 1, fp) == 1) {
        if (p.empId == targetId) {
            found = 1;
            
            printf("\n--- Updating Figures for %s ---", p.name);
            printf("\nEnter New Basic Salary: ");
            scanf("%f", &p.basicSalary);

            printf("Enter New HRA: ");
            scanf("%f", &p.hra);

            printf("Enter New Medical Allowance: ");
            scanf("%f", &p.medical);

            printf("Enter New Income Tax Deduction: ");
            scanf("%f", &p.tax);

            // Recompute values before writing
            calculateNetSalary(&p);

            // Step back file system stream head pointer 
            fseek(fp, -sizeof(Payroll), SEEK_CUR);
            fwrite(&p, sizeof(Payroll), 1, fp);
            printf("\nSalary package updated and ledger rebalanced successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}