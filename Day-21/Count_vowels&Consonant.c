#include <stdio.h>

int main() {
    char str[150];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    // Note the space before %: " %[^\n]" clears any leftover newlines
    scanf(" %[^\n]", str); 

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Check if the character is a lowercase letter
        int is_lowercase = (ch >= 'a' && ch <= 'z');
        // Check if the character is an uppercase letter
        int is_uppercase = (ch >= 'A' && ch <= 'Z');

        // Only process if it's an actual letter
        if (is_lowercase || is_uppercase) {
            
            // Check if it's a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } 
            // If it's a letter but not a vowel, it's a consonant
            else {
                conconants++; // Typo safety check: consonants
                consonants++;
            }
        }
    }

    printf("\n--- Results ---\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}