#include <stdio.h>
#include <ctype.h>

// Structure to hold question data
typedef struct {
    char question[150];
    char options[4][50];
    char correctAnswer;
} QuizQuestion;

int main() {
    // Array of quiz questions
    QuizQuestion quiz[5] = {
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. C", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the size of an 'int' data type in C (typically on a 64-bit system)?",
            {"A. 2 Bytes", "B. 4 Bytes", "C. 8 Bytes", "D. 1 Byte"},
            'B'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. const", "D. immutable"},
            'C'
        },
        {
            "What is the correct file extension for a C source file?",
            {"A. .c", "B. .cpp", "C. .class", "D. .h"},
            'A'
        },
        {
            "Which function is used to read a character from the console in C?",
            {"A. printf()", "B. scanf()", "C. gets()", "D. getchar()"},
            'D'
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    char userAnswer;

    printf("==================================================\n");
    printf("           WELCOME TO THE COMPUTER SCIENCE QUIZ    \n");
    printf("==================================================\n");
    printf("Instructions: Enter A, B, C, or D for each question.\n\n");

    // Loop through each question
    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        
        // Print the 4 options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Get and validate user input
        while (1) {
            printf("Your Answer: ");
            scanf(" %c", &userAnswer); // Notice the space before %c to skip whitespace
            userAnswer = toupper(userAnswer); // Convert to uppercase for uniformity

            if (userAnswer == 'A' || userAnswer == 'B' || userAnswer == 'C' || userAnswer == 'D') {
                break; // Valid input, break the inner loop
            } else {
                printf("❌ Invalid choice! Please enter A, B, C, or D.\n");
            }
        }

        // Check if the answer is correct
        if (userAnswer == quiz[i].correctAnswer) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Incorrect! The correct answer was %c.\n\n", quiz[i].correctAnswer);
        }
        printf("--------------------------------------------------\n");
    }

    // Final Scoreboard Display
    printf("\n==================================================\n");
    printf("                  QUIZ COMPLETED!                 \n");
    printf("==================================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    
    // Percentage breakdown and remarks
    double percentage = ((double)score / totalQuestions) * 100;
    printf("Percentage: %.1f%%\n", percentage);
    
    if (percentage == 100.0) {
        printf("Remarks: Perfect score! You're a C expert! 🌟\n");
    } else if (percentage >= 70.0) {
        printf("Remarks: Great job! Highly proficient. 👍\n");
    } else if (percentage >= 40.0) {
        printf("Remarks: Good effort, but room for improvement. 📚\n");
    } else {
        printf("Remarks: Better luck next time. Keep practicing! 💻\n");
    }
    printf("==================================================\n");

    return 0;
}