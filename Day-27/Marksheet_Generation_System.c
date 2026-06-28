#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "marksheets.dat"
#define NUM_SUBJECTS 5

// Define the Marksheet structure
typedef struct {
    int rollNo;
    char name[50];
    char className[20];
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    char grade[5];
} Marksheet;

// Subject name tracker
const char* subjectNames[NUM_SUBJECTS] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Science"};

// Function Prototypes
void addMarksheet();
void displayAllSummary();
void generateReportCard();
void calculateAcademicMetrics(Marksheet *m);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n    MARKSHEET GENERATION SYSTEM     ");
        printf("\n====================================");
        printf("\n1. Add New Student Marks");
        printf("\n2. Display Performance Summary Table");
        printf("\n3. Generate Detailed Report Card Slip");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMarksheet(); break;
            case 2: displayAllSummary(); break;
            case 3: generateReportCard(); break;
            case 4: 
                printf("\nExiting Marksheet System. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
}

// Helper function to process marks, percentages, and global letter grades
void calculateAcademicMetrics(Marksheet *m) {
    m->totalMarks = 0;
    int failed = 0;

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        m->totalMarks += m->marks[i];
        if (m->marks[i] < 33) { // 33 out of 100 is passing
            failed = 1;
        }
    }

    // Assumes each subject is out of 100 max points
    m->percentage = (float)m->totalMarks / NUM_SUBJECTS;

    // Determine Grade boundaries
    if (failed) {
        strcpy(m->grade, "FAIL");
    } else if (m->percentage >= 90.0) {
        strcpy(m->grade, "A+");
    } else if (m->percentage >= 80.0) {
        strcpy(m->grade, "A");
    } else if (m->percentage >= 70.0) {
        strcpy(m->grade, "B");
    } else if (m->percentage >= 60.0) {
        strcpy(m->grade, "C");
    } else if (m->percentage >= 50.0) {
        strcpy(m->grade, "D");
    } else if (m->percentage >= 33.0) {
        strcpy(m->grade, "E");
    } else {
        strcpy(m->grade, "FAIL");
    }
}

// 1. Collect academic parameters and score metrics
void addMarksheet() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError accessing storage system!");
        return;
    }

    Marksheet m;
    printf("\nEnter Roll Number: ");
    scanf("%d", &m.rollNo);
    getchar(); // Clear buffer newline

    printf("Enter Student Name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = 0;

    printf("Enter Class/Section: ");
    fgets(m.className, sizeof(m.className), stdin);
    m.className[strcspn(m.className, "\n")] = 0;

    printf("\n--- Enter Marks (out of 100) ---\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        while (1) {
            printf("%s: ", subjectNames[i]);
            scanf("%d", &m.marks[i]);
            if (m.marks[i] >= 0 && m.marks[i] <= 100) {
                break;
            }
            printf("Invalid marks! Please input a value between 0 and 100.\n");
        }
    }

    // Calculate parameters
    calculateAcademicMetrics(&m);

    fwrite(&m, sizeof(Marksheet), 1, fp);
    fclose(fp);

    printf("\nStudent score entry processed and saved successfully!\n");
}

// 2. Read and present a macro level layout tracking grid
void displayAllSummary() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo student history data found. Add some records first!\n");
        return;
    }

    Marksheet m;
    printf("\n-----------------------------------------------------------------------------");
    printf("\n%-9s %-22s %-10s %-12s %-12s %-6s", "Roll No", "Name", "Class", "Total (500)", "Percentage", "Grade");
    printf("\n-----------------------------------------------------------------------------");

    while (fread(&m, sizeof(Marksheet), 1, fp) == 1) {
        printf("\n%-9d %-22s %-10s %-12d %-12.2f %-6s", 
               m.rollNo, m.name, m.className, m.totalMarks, m.percentage, m.grade);
    }
    printf("\n-----------------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Search for a specific student and build a formal high-fidelity report card
void generateReportCard() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nMarksheet record repository is empty.\n");
        return;
    }

    int targetRoll, found = 0;
    Marksheet m;

    printf("\nEnter Student Roll Number to print report card: ");
    scanf("%d", &targetRoll);

    while (fread(&m, sizeof(Marksheet), 1, fp) == 1) {
        if (m.rollNo == targetRoll) {
            found = 1;
            printf("\n==========================================================");
            printf("\n                  OFFICIAL REPORT CARD                    ");
            printf("\n==========================================================");
            printf("\n Roll Number : %-15d Class/Sec : %-10s", m.rollNo, m.className);
            printf("\n Name        : %-40s", m.name);
            printf("\n----------------------------------------------------------");
            printf("\n %-25s | %-10s | %-10s", "SUBJECT NAME", "MAX MARKS", "OBTAINED");
            printf("\n----------------------------------------------------------");
            
            for (int i = 0; i < NUM_SUBJECTS; i++) {
                printf("\n %-25s | %-10d | %-10d", subjectNames[i], 100, m.marks[i]);
            }
            
            printf("\n----------------------------------------------------------");
            printf("\n AGGREGATE TOTAL      : %d / %d", m.totalMarks, NUM_SUBJECTS * 100);
            printf("\n FINAL PERCENTAGE     : %.2f%%", m.percentage);
            printf("\n FINAL ACADEMIC GRADE : %s", m.grade);
            printf("\n==========================================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nNo student record found matching Roll Number %d.\n", targetRoll);
    }
    fclose(fp);
}