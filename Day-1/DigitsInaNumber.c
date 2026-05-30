#include <stdio.h>
int main(){
int num,originalNum,count=0;
printf("Enter any number: \n");
scanf("%d",&num);
originalNum=num;
do{
    num/=10;
    count++;
} while(num>0);


printf("number of digits in %d is %d",originalNum,count);
return 0;
}