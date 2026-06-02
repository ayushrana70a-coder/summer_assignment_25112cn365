#include <stdio.h>
int main() {
int num,i,first = 0,second = 1,next;
printf("Enter the number of terms : ");
scanf("%d",&num);
if(num == 1){
    printf("Nth Fibonacci term = %d\n",first);
} else if(num == 2){
    printf("Nth Fibonacci term = %d",second);
} else {
    for(i = 3; i <=num; i++){
    next = first + second;
    first = second;
    second = next;
    }
    printf("Nth Fibonacci term = %d",second);
 }
return 0;
}