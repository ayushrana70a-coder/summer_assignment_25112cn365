#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void add();
void subtract();
void multiply();
void divide();
void modulus();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n====================================");
        printf("\n      MENU-DRIVEN CALCULATOR        ");
        printf("\n====================================");
        printf("\n1. Addition (+)");
        printf("\n2. Subtraction (-)");
        printf("\n3. Multiplication (*)");
        printf("\n4. Division (/)");
        printf("\n5. Modulus Remainder (%%)");
        printf("\n6. Exit");
        printf("\nEnter your calculation choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: 
                printf("\nShutting down calculator. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid selection! Please enter a valid menu option.\n");
        }
    }
}

// 1. Addition Operation
void add() {
    double a, b;
    printf("\nEnter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.4f + %.4f = **%.4f**\n", a, b, a + b);
}

// 2. Subtraction Operation
void subtract() {
    double a, b;
    printf("\nEnter two numbers to subtract (First - Second): ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.4f - %.4f = **%.4f**\n", a, b, a - b);
}

// 3. Multiplication Operation
void multiply() {
    double a, b;
    printf("\nEnter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.4f * %.4f = **%.4f**\n", a, b, a * b);
}

// 4. Division Operation with safety bounds check
void divide() {
    double a, b;
    printf("\nEnter dividend and divisor (Numerator / Denominator): ");
    scanf("%lf %lf", &a, &b);
    
    // Critical Runtime Guardrail: Division-by-zero check
    if (b == 0.0) {
        printf("\nMath Error: Division by zero is undefined!\n");
    } else {
        printf("Result: %.4f / %.4f = **%.4f**\n", a, b, a / b);
    }
}

// 5. Modulus Operation using Explicit Integer Typecasting
void modulus() {
    double a, b;
    printf("\nEnter two numbers to find remainder: ");
    scanf("%lf %lf", &a, &b);

    // Critical Guardrail: Modulo-by-zero check
    if (b == 0.0) {
        printf("\nMath Error: Modulo by zero is undefined!\n");
    } else {
        // C requires integer types for the % operator, so we typecast double to int
        int intA = (int)a;
        int intB = (int)b;
        printf("Result (Integer Modulo): %d %% %d = **%d**\n", intA, intB, intA % intB);
        if (a != intA || b != intB) {
            printf("*(Note: Decimal values were truncated to integers for remainder computation)*\n");
        }
    }
}