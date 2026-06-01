#include <stdio.h>
int find_gcd(int a, int b) {
    if (b == 0)
        return a;
    return find_gcd(b, a % b);
}
int main(){
int num1,num2;
printf("Enter two numbers: ");
scanf("%d %d", &num1, &num2);
printf("The GCD of %d and %d is: %d", num1, num2, find_gcd(num1, num2));
return 0;
}
