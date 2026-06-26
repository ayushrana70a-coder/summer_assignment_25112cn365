#include <stdio.h>

// Function declarations
void showMenu();
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    int choice;
    double balance = 1000.00; // Starting default balance
    int pin = 1234;
    int enteredPin;
    int pinAttempts = 0;

    printf("=========================================\n");
    printf("         WELCOME TO THE APEX BANK        \n");
    printf("=========================================\n");

    // Simple PIN security check (Default PIN: 1234)
    while (pinAttempts < 3) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input. Numbers only.\n\n");
            while (getchar() != '\n'); // Clear buffer
            pinAttempts++;
            continue;
        }

        if (enteredPin == pin) {
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - pinAttempts);
        }
    }

    if (pinAttempts == 3) {
        printf("Too many incorrect attempts. Your card has been blocked!\n");
        return 0;
    }

    // Main ATM Loop
    do {
        showMenu();
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n❌ Invalid selection. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            choice = 0; // Reset choice to trigger default case
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using Apex Bank. Goodbye!\n");
                break;
            default:
                printf("\n❌ Invalid choice! Please select an option between 1 and 4.\n");
        }
    } while (choice != 4);

    printf("=========================================\n");
    return 0;
}

// Function to display the ATM menu
void showMenu() {
    printf("\n---------- ATM MENU ----------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

// Function to print current balance
void checkBalance(double balance) {
    printf("\n💰 Your current balance is: $%.2f\n", balance);
}

// Function to deposit money
double depositMoney(double balance) {
    double amount;
    printf("\nEnter amount to deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("❌ Invalid amount! You cannot deposit zero or negative cash.\n");
    } else {
        balance += amount;
        printf("✅ Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
    }
    return balance;
}

// Function to withdraw money
double withdrawMoney(double balance) {
    double amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("❌ Invalid amount! Please enter a value greater than zero.\n");
    } else if (amount > balance) {
        printf("❌ Insufficient Funds! Your current balance is $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("✅ Please collect your cash.\n");
        printf("✅ Successfully withdrew $%.2f. Remaining balance: $%.2f\n", amount, balance);
    }
    return balance;
}