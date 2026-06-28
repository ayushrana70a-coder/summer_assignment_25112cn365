#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 60
#define NAME_LIMIT 50
#define ROLL_LIMIT 15

// Structure definition to store an individual student profile
typedef struct {
    char rollNumber[ROLL_LIMIT];
    char name[NAME_LIMIT];
    float marks;
    char grade;
} Student;

// Function Prototypes
void addStudent(Student records[], int *count);
void displayRecords(Student records[], int count);
void searchByRoll(Student records[], int count);
void calculateStatistics(Student records[], int count);
char calculateGrade(float marks);
int findStudentIndexByRoll(Student records[], int count, const char roll[]);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    Student records[MAX_STUDENTS];
    int count = 0; // Master counter tracking active registered students
    int choice;

    while (1) {
        printf("\n====================================");
        printf("\n        STUDENT RECORD SYSTEM       ");
        printf("\n====================================");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student by Roll Number");
        printf("\n4. View Class Performance Stats");
        printf("\n5. Exit");
        printf("\nEnter your selection (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addStudent(records, &count); 
                break;
            case 2: 
                displayRecords(records, count); 
                break;
            case 3: 
                searchByRoll(records, count); 
                break;
            case 4: 
                calculateStatistics(records, count); 
                break;
            case 5: 
                printf("\nExiting Student Database System. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please enter an option from 1 to 5.\n");
        }
    }
}

// Helper Function: Generates academic grading metrics based on mark percentage
char calculateGrade(float marks) {
    if (marks >= 90.0) return 'A';
    else if (marks >= 80.0) return 'B';
    else if (marks >= 70.0) return 'C';
    else if (marks >= 60.0) return 'D';
    else if (marks >= 40.0) return 'E';
    else return 'F';
}

// Helper Function: Linear search utility to prevent duplicate roll numbers
int findStudentIndexByRoll(Student records[], int count, const char roll[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].rollNumber, roll) == 0) {
            return i; // Returns matching index profile position
        }
    }
    return -1; // Unique or nonexistent roll number
}

// 1. Insert Record with Unique Identification Guardrails
void addStudent(Student records[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase Error: System capacity limit reached (%d max)!\n", MAX_STUDENTS);
        return;
    }

    char tempRoll[ROLL_LIMIT];
    printf("\nEnter Roll Number (alphanumeric, no spaces): ");
    scanf("%s", tempRoll);

    // Business Logic Validation: Ensure Roll Numbers are unique identifiers
    if (findStudentIndexByRoll(records, *count, tempRoll) != -1) {
        printf("\nError: A student with Roll Number \"%s\" is already registered!\n", tempRoll);
        return;
    }

    strcpy(records[*count].rollNumber, tempRoll);

    printf("Enter Student Full Name: ");
    getchar(); // Clear internal dangling newline trailing buffer
    fgets(records[*count].name, NAME_LIMIT, stdin);
    records[*count].name[strcspn(records[*count].name, "\n")] = '\0'; // Strip newline character cleanly

    printf("Enter Total Marks obtained (0.0 to 100.0): ");
    scanf("%f", &records[*count].marks);
    
    // Bounds enforcement loop
    while (records[*count].marks < 0.0 || records[*count].marks > 100.0) {
        printf("Invalid entry! Marks must fall between 0.0 and 100.0. Re-enter: ");
        scanf("%f", &records[*count].marks);
    }

    // Assign grade automatically based on verified marks boundary
    records[*count].grade = calculateGrade(records[*count].marks);

    (*count)++; // Increment database registration footprint scale
    printf("\nSuccess: Student profile successfully logged!\n");
}

// 2. Output All Formatted Database Rows
void displayRecords(Student records[], int count) {
    if (count == 0) {
        printf("\nNo student records logged in the system currently.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------\n");
    printf("%-15s %-30s %-12s %-6s\n", "Roll No", "Student Name", "Marks (%)", "Grade");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-30s %-12.2f %-6c\n", 
               records[i].rollNumber, 
               records[i].name, 
               records[i].marks, 
               records[i].grade);
    }
    printf("-----------------------------------------------------------------------\n");
}

// 3. String Query Match Lookup
void searchByRoll(Student records[], int count) {
    if (count == 0) {
        printf("\nDatabase is empty. No index exists to search.\n");
        return;
    }

    char targetRoll[ROLL_LIMIT];
    printf("\nEnter the Roll Number to search: ");
    scanf("%s", targetRoll);

    int index = findStudentIndexByRoll(records, count, targetRoll);

    if (index == -1) {
        printf("\nRecord Match Failed: No profile found for Roll Number \"%s\".\n", targetRoll);
    } else {
        printf("\n--- Student Profile Located ---");
        printf("\nRoll Number: %s", records[index].rollNumber);
        printf("\nFull Name:   %s", records[index].name);
        printf("\nFinal Marks: %.2f%%", records[index].marks);
        printf("\nGrade:       [%c]\n", records[index].grade);
    }
}

// 4. Analytics: Mathematical Aggregations over Class Bounds
void calculateStatistics(Student records[], int count) {
    if (count == 0) {
        printf("\nClass statistics cannot be generated with empty parameters.\n");
        return;
    }

    float sum = 0;
    float highest = records[0].marks;
    float lowest = records[0].marks;
    int highestIndex = 0, lowestIndex = 0;

    for (int i = 0; i < count; i++) {
        sum += records[i].marks;

        if (records[i].marks > highest) {
            highest = records[i].marks;
            highestIndex = i;
        }
        if (records[i].marks < lowest) {
            lowest = records[i].marks;
            lowestIndex = i;
        }
    }

    float average = sum / count;

    printf("\n=================================================");
    printf("\n          CLASS PERFORMANCE ANALYSIS             ");
    printf("\n=================================================");
    printf("\nTotal Students Evaluated: %d", count);
    printf("\nClass Average Performance: **%.2f%%**", average);
    printf("\nClass Topper:            **%s** (Roll: %s) with %.2f%%", records[highestIndex].name, records[highestIndex].rollNumber, highest);
    printf("\nLowest Performer:        **%s** (Roll: %s) with %.2f%%", records[lowestIndex].name, records[lowestIndex].rollNumber, lowest);
    printf("\n=================================================\n");
}