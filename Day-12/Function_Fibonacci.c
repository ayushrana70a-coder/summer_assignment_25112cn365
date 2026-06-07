#include <stdio.h>
void Fibonacci(int terms) {
    int first = 0, second = 1, nextTerm;

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= terms; ++i) {
        printf("%d ", first);
        
        nextTerm = first + second;
        first = second;
        second = nextTerm;
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter the number of terms to print: ");
    scanf("%d", &num);

    // Call the function
    Fibonacci(num);

    return 0;
}