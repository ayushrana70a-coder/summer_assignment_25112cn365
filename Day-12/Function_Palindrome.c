#include <stdio.h>
#include <stdbool.h>

// Easy function to reverse and check the number
bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    int remainder;

    // Reverse the number step-by-step
    while (num > 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num = num / 10;
    }

    // Check if the reversed version matches the original
    if (originalNum == reversedNum) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is NOT a palindrome.\n", num);
    }

    return 0;
}