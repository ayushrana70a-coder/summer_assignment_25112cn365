#include <stdio.h>

int main() {
    int age;
    const int VOTING_AGE = 18; // Standard voting age threshold

    printf("=========================================\n");
    printf("       VOTING ELIGIBILITY SYSTEM         \n");
    printf("=========================================\n");

    printf("Please enter your age: ");
    
    // Validate input to ensure it's a valid integer
    if (scanf("%d", &age) != 1) {
        printf("\n❌ Error: Invalid input! Please enter a valid number.\n");
        return 1; // Exit program with an error code
    }

    // Check for unrealistic or negative age inputs
    if (age < 0 || age > 120) {
        printf("\n❌ Error: Please enter a realistic age between 0 and 120.\n");
    } 
    // Check voting eligibility
    else if (age >= VOTING_AGE) {
        printf("\n✅ Congratulations! You are %d years old.\n", age);
        printf("You are ELIGIBLE to cast your vote.\n");
    } 
    else {
        printf("\n⛔ Sorry, you are only %d years old.\n", age);
        printf("You are NOT eligible to vote yet.\n");
        printf("You need to wait %d more year(s).\n", VOTING_AGE - age);
    }

    printf("=========================================\n");
    return 0;
}