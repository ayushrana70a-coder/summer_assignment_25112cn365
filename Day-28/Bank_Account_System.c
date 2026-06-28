#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "accounts.dat"
#define MIN_BALANCE 500.00 // Minimum balance required to keep account active

// Define the Account structure
typedef struct {
    int accountNumber;
    char name[50];
    char accountType[20]; // Savings, Current, etc.
    float balance;
} Account;

// Function Prototypes
void createAccount();
void displayAllAccounts();
void checkBalance();
void depositMoney();
void withdrawMoney();
void transferFunds();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n       SECURE BANKING SYSTEM        ");
        printf("\n====================================");
        printf("\n1. Open New Account");
        printf("\n2. Display All Accounts (Admin Only)");
        printf("\n3. Check Account Balance / Details");
        printf("\n4. Deposit Funds");
        printf("\n5. Withdraw Funds");
        printf("\n6. Transfer Funds (Wire)");
        printf("\n7. Exit");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAllAccounts(); break;
            case 3: checkBalance(); break;
            case 4: depositMoney(); break;
            case 5: withdrawMoney(); break;
            case 6: transferFunds(); break;
            case 7: 
                printf("\nThank you for banking with us. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
        }
    }
}

// 1. Open a fresh account registry block
void createAccount() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError accessing banking database system!");
        return;
    }

    Account acc;
    printf("\n--- Open New Account ---");
    printf("\nAssign Account Number: ");
    scanf("%d", &acc.accountNumber);
    getchar(); // Clear trailing newline buffer

    printf("Enter Account Holder Full Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0; // Strip newline character

    printf("Enter Account Type (Savings / Current): ");
    fgets(acc.accountType, sizeof(acc.accountType), stdin);
    acc.accountType[strcspn(acc.accountType, "\n")] = 0;

    while (1) {
        printf("Enter Initial Deposit (Min $%.2f): ", MIN_BALANCE);
        scanf("%f", &acc.balance);
        if (acc.balance >= MIN_BALANCE) {
            break;
        }
        printf("Insufficient opening amount! Minimum deposit must be at least $%.2f.\n", MIN_BALANCE);
    }

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully for %s!\n", acc.name);
}

// 2. Read and view all ledger allocations globally
void displayAllAccounts() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo banking records exist yet.\n");
        return;
    }

    Account acc;
    printf("\n-----------------------------------------------------------------------");
    printf("\n%-12s %-25s %-18s %-12s", "Acc No.", "Account Holder", "Type", "Balance");
    printf("\n-----------------------------------------------------------------------");

    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        printf("\n%-12d %-25s %-18s $%-11.2f", acc.accountNumber, acc.name, acc.accountType, acc.balance);
    }
    printf("\n-----------------------------------------------------------------------\n");
    fclose(fp);
}

// 3. Query a single account identity breakdown
void checkBalance() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nBanking ledger registry is unreadable.\n");
        return;
    }

    int searchAcc, found = 0;
    Account acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &searchAcc);

    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.accountNumber == searchAcc) {
            found = 1;
            printf("\n--- Account Profile ---");
            printf("\nAccount Number: %d", acc.accountNumber);
            printf("\nHolder Name   : %s", acc.name);
            printf("\nAccount Type  : %s", acc.accountType);
            printf("\nActive Balance: $%.2f\n", acc.balance);
            break;
        }
    }

    if (!found) printf("\nAccount number %d not found.\n", searchAcc);
    fclose(fp);
}

// 4. Add floating credit into file offset
void depositMoney() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nDatabase system connection failed.\n");
        return;
    }

    int targetAcc, found = 0;
    float amount;
    Account acc;

    printf("\nEnter Account Number for Deposit: ");
    scanf("%d", &targetAcc);

    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.accountNumber == targetAcc) {
            found = 1;
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("\nInvalid deposit value amount entered.\n");
            } else {
                acc.balance += amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("\nSuccess! Deposited $%.2f. New Balance: $%.2f\n", amount, acc.balance);
            }
            break;
        }
    }

    if (!found) printf("\nAccount number %d not found.\n", targetAcc);
    fclose(fp);
}

// 5. Debit cash allocations while monitoring limits
void withdrawMoney() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nDatabase connection error.\n");
        return;
    }

    int targetAcc, found = 0;
    float amount;
    Account acc;

    printf("\nEnter Account Number for Withdrawal: ");
    scanf("%d", &targetAcc);

    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.accountNumber == targetAcc) {
            found = 1;
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("\nInvalid withdrawal magnitude entry.\n");
            } else if (acc.balance - amount < MIN_BALANCE) {
                printf("\nTransaction Denied! Maintaining the required minimum balance of $%.2f would be breached.\n", MIN_BALANCE);
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("\nSuccess! Withdrew $%.2f. Remaining Balance: $%.2f\n", amount, acc.balance);
            }
            break;
        }
    }

    if (!found) printf("\nAccount number %d not found.\n", targetAcc);
    fclose(fp);
}

// 6. Direct transaction routing engine linking two ledger footprints
void transferFunds() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nCritical ledger database linking error!\n");
        return;
    }

    int senderAcc, receiverAcc;
    int senderIdx = -1, receiverIdx = -1;
    float transferAmount;
    Account acc;
    
    printf("\nEnter Your (Sender) Account Number: ");
    scanf("%d", &senderAcc);
    printf("Enter Destination (Receiver) Account Number: ");
    scanf("%d", &receiverAcc);

    if (senderAcc == receiverAcc) {
        printf("\nError: Source and target endpoints cannot be identical.\n");
        fclose(fp);
        return;
    }

    printf("Enter Amount to Wire Transfer: ");
    scanf("%f", &transferAmount);

    if (transferAmount <= 0) {
        printf("\nInvalid wire transfer magnitude threshold specified.\n");
        fclose(fp);
        return;
    }

    long int pos = 0;
    Account s, r; // Temp containers for storage matching

    // Locate both accounts and capture their positions in the file
    while (fread(&acc, sizeof(Account), 1, fp) == 1) {
        if (acc.accountNumber == senderAcc) {
            s = acc;
            senderIdx = pos;
        }
        if (acc.accountNumber == receiverAcc) {
            r = acc;
            receiverIdx = pos;
        }
        pos = ftell(fp); // Tracks position tracking offsets 
    }

    // Verify system operations constraints metrics
    if (senderIdx == -1) {
        printf("\nTransaction Cancelled: Sending entity not found.\n");
    } else if (receiverIdx == -1) {
        printf("\nTransaction Cancelled: Destination account placeholder not found.\n");
    } else if (s.balance - transferAmount < MIN_BALANCE) {
        printf("\nTransaction Cancelled: Sender has insufficient balance to back this wire.\n");
    } else {
        // Execute Debit from Sender
        s.balance -= transferAmount;
        fseek(fp, senderIdx, SEEK_SET);
        fwrite(&s, sizeof(Account), 1, fp);

        // Execute Credit to Receiver
        r.balance += transferAmount;
        fseek(fp, receiverIdx, SEEK_SET);
        fwrite(&r, sizeof(Account), 1, fp);

        printf("\nTransaction Wire Complete! Sent $%.2f from Acc #%d to Acc #%d successfully.\n", 
               transferAmount, senderAcc, receiverAcc);
    }
    
    fclose(fp);
}