#include <stdio.h>
int main(){
int num,i,remainder,sum=0,temp;
printf("enter any integer : ");
scanf("%d",&num);
temp=num;
while(num!=0){
remainder=num%10;
sum+=remainder;
num/=10;
}
printf("The sum of digits of %d is %d\n",temp,sum);
return 0;
}


