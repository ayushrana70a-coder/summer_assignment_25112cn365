#include <stdio.h>
int main(){
int num,remainder,product,temp;
printf("\nEnter any number : ");
scanf("%d",&num);
temp = num;
for(product = 1;num > 0;num /= 10){
remainder = num % 10;
product *= remainder;
}
printf("\nThe product of digits of %d is %d",temp,product);
return 0;
}