#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("===================================\n");
    printf("    WELCOME TO THE GUESSING GAME   \n");
    printf("===================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Loop until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Validate input to ensure it's a number
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess > secret_number) {
            printf("Too high! Try again.\n\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("\n🎉 CONGRATULATIONS! You guessed it! 🎉\n");
            printf("The secret number was %d.\n", secret_number);
            printf("It took you %d attempts.\n", attempts);
        }

    } while (guess != secret_number);

    printf("===================================\n");
    printf("Thank you for playing!\n");
    
    return 0;
}