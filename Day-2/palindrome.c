#include <stdio.h>
int main(){
int num,temp,remainder,rev = 0;
printf("\nEnter any number :");
scanf("%d",&num);
temp = num;
while(num!=0){
remainder = num%10;
rev = rev*10 + remainder;
num /= 10;
}
if(temp == rev){
printf("\nEntered number is palindrome");
}
else{
printf("\nEntered number is not palindrome");
}
return 0;
}