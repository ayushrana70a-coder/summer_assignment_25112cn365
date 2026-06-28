#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LIMIT 50
#define ACC_NUM_LIMIT 12

// Global Parallel Data Structures (Simulating a database)
char accountNumbers[MAX_ACCOUNTS][ACC_NUM_LIMIT];
char accountNames[MAX_ACCOUNTS][NAME_LIMIT];
double balances[MAX_ACCOUNTS];
int accountCount = 0; // Tracks the absolute number of registered profiles

// Function Prototypes
void createAccount();
void displayAllAccounts();
void depositMoney();
void withdrawMoney();
void transferFunds();
void checkBalance();
int findAccountIndex(const char accNum[]);
void cleanInputBuffer();
void displayMenu();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;
    while (1) {
        printf("\n==================================================");
        printf("\n             APEX DIGITAL BANKING SYSTEM          ");
        printf("\n==================================================");
        printf("\n1. Create Fresh Bank Account");
        printf("\n2. Display Master Account Registry Ledger");
        printf("\n3. Cash Deposit Transaction");
        printf("\n4. Cash Withdrawal Transaction");
        printf("\n5. Inter-Bank Account Fund Transfer");
        printf("\n6. Balance Inquiry");
        printf("\n7. Exit Application");
        printf("\nEnter choice sequence (1-7): ");
        scanf("%d", &choice);
        cleanInputBuffer();

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAllAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: transferFunds(); break;
            case 6: checkBalance(); break;
            case 7: 
                printf("\nDisconnecting from banking network servers. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid Selection! Please input a valid selection code.\n");
        }
    }
}

// Core Helper Function: Linear search algorithm matching tracking alphanumeric index tags
int findAccountIndex(const char accNum[]) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accountNumbers[i], accNum) == 0) {
            return i; // Target account matching index found
        }
    }
    return -1; // Target account string reference does not exist
}

// Core Helper Function: Safely clears out lingering trailing \n flags inside standard stream buffers
void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Onboard a fresh client profile with structural guardrails
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nServer Error: Core storage full! Cannot onboard more bank accounts.\n");
        return;
    }

    char tempAccNum[ACC_NUM_LIMIT];
    printf("\nCreate Unique Alphanumeric Account Number (Max 11 chars): ");
    scanf("%11s", tempAccNum);
    cleanInputBuffer();

    // Core Guardrail: Primary Unique Key verification mapping check
    if (findAccountIndex(tempAccNum) != -1) {
        printf("\nRegistration Failure: Account number \"%s\" already exists!\n", tempAccNum);
        return;
    }

    // Assign account string code to target row index
    strcpy(accountNumbers[accountCount], tempAccNum);

    printf("Enter Account Holder Full Name: ");
    fgets(accountNames[accountCount], NAME_LIMIT, stdin);
    accountNames[accountCount][strcspn(accountNames[accountCount], "\n")] = '\0'; // Strip newline cleanly

    printf("Enter Minimum Initial Security Deposit Amount: $");
    scanf("%lf", &balances[accountCount]);
    
    while (balances[accountCount] < 0.0) {
        printf("Invalid Value! Starting base ledger balance cannot be negative. Re-enter: $");
        scanf("%lf", &balances[accountCount]);
    }

    printf("\nSuccess: Account **%s** successfully registered for %s!\n", 
           accountNumbers[accountCount], accountNames[accountCount]);
    accountCount++; // Scale up banking active balance registry index
}

// 2. Output global multi-tiered grid report matrix sheet rows
void displayAllAccounts() {
    if (accountCount == 0) {
        printf("\nNo customer accounts logged on the server network currently.\n");
        return;
    }

    printf("\n----------------------------------------------------------------------\n");
    printf("%-5s %-15s %-30s %-15s\n", "S.No", "Account No", "Account Holder Name", "Balance Ledger");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%-5d %-15s %-30s $%-14.2f\n", 
               i + 1, accountNumbers[i], accountNames[i], balances[i]);
    }
    printf("----------------------------------------------------------------------\n");
}

// 3. Deposit transaction updating state row elements
void depositMoney() {
    char accNum[ACC_NUM_LIMIT];
    double amount;

    printf("\nEnter Target Account Number for Deposit: ");
    scanf("%11s", accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nTransaction Aborted: Account reference not found.\n");
        return;
    }

    printf("Account Verified [%s]. Enter deposit amount: $", accountNames[index]);
    scanf("%lf", &amount);

    if (amount <= 0.0) {
        printf("Transaction Terminated: Deposit values must register greater than $0.00\n");
    } else {
        balances[index] += amount; // Mutation update step
        printf("\nTransaction Finalized! **$%.2f** loaded. Updated Balance: $%.2f\n", amount, balances[index]);
    }
}

// 4. Withdrawal sequence tracking ledger capacity constraints
void withdrawMoney() {
    char accNum[ACC_NUM_LIMIT];
    double amount;

    printf("\nEnter Target Account Number for Withdrawal: ");
    scanf("%11s", accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nTransaction Aborted: Account reference not found.\n");
        return;
    }

    printf("Account Verified [%s]. Enter withdrawal amount: $", accountNames[index]);
    scanf("%lf", &amount);

    if (amount <= 0.0) {
        printf("Transaction Terminated: Invalid processing value bounds.\n");
    } else if (amount > balances[index]) {
        // Business Rule: Overdraft protection validation check
        printf("\nTransaction Denied: Deficient Vault Balance! Current available funds: $%.2f\n", balances[index]);
    } else {
        balances[index] -= amount; // Mutation drop step
        printf("\nTransaction Finalized! **$%.2f** withdrawn. Remaining Balance: $%.2f\n", amount, balances[index]);
    }
}

// 5. Inter-Bank transactional engine executing state adjustments across different array nodes
void transferFunds() {
    char sourceAcc[ACC_NUM_LIMIT], destAcc[ACC_NUM_LIMIT];
    double amount;

    printf("\nEnter Your Source Account Number: ");
    scanf("%11s", sourceAcc);
    int srcIndex = findAccountIndex(sourceAcc);

    if (srcIndex == -1) {
        printf("\nTransfer Aborted: Source Account reference not found.\n");
        return;
    }

    printf("Enter Beneficiary Destination Account Number: ");
    scanf("%11s", destAcc);
    int destIndex = findAccountIndex(destAcc);

    if (destIndex == -1) {
        printf("\nTransfer Aborted: Beneficiary account destination matching failed.\n");
        return;
    }

    if (srcIndex == destIndex) {
        printf("\nLogic Error: Source account and destination accounts cannot match identical values.\n");
        return;
    }

    printf("Linking [%s] -> [%s]. Enter transfer volume amount: $", accountNames[srcIndex], accountNames[destIndex]);
    scanf("%lf", &amount);

    if (amount <= 0.0) {
        printf("Transaction Terminated: Invalid currency range assignment parameters.\n");
    } else if (amount > balances[srcIndex]) {
        printf("\nTransfer Terminated: Insufficient available balance margin inside source parameters!\n");
    } else {
        // Dual-Node Mutation step mapping atomicity logic actions
        balances[srcIndex] -= amount;
        balances[destIndex] += amount;
        printf("\nSuccess: Wired **$%.2f** safely to account %s!\n", amount, accountNumbers[destIndex]);
    }
}

// 6. Direct entry key balancing view
void checkBalance() {
    char accNum[ACC_NUM_LIMIT];
    printf("\nEnter Account Number for Balance Inquiry: ");
    scanf("%11s", accNum);

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nInquiry Failed: Account parameter not linked to active records.\n");
    } else {
        printf("\n--- Real-Time Audit Summary ---");
        printf("\nAccount Tag: %s", accountNumbers[index]);
        printf("\nHolder Name: %s", accountNames[index]);
        printf("\nNet Balance: **$%.2f**\n", balances[index]);
    }
}