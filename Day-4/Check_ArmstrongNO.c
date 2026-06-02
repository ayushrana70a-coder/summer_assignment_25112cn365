#include <stdio.h>
#include <math.h>
int main(){
int num, i, remainder, original, count = 0, result = 0, temp;
printf("Enter the number : ");
scanf("%d",&num);
original = num;
temp = num; // count the number of digits
while(temp > 0){
    count++;
    temp /= 10;
}

temp = num;
while(temp > 0){
remainder = temp % 10;
result += pow(remainder,count);
temp /= 10;
}
if(result == original)
    printf("%d is an Armstrong number\n",original);
else
    printf("%d is NOT an Armstrong number\n",original);
return 0;
}