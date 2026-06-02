#include <stdio.h>
int main() {
int num,i,first = 0,second = 1,next;
printf("Enter the number of terms :");
scanf("%d",&num);
printf("Fibonacci series : ");
for(i = 1;i <= num;i++){
printf("%d",first);
next = first + second;
first = second;
second = next;
}
return 0;
}