#include <stdio.h>
#include <string.h>
int main(){
char num[50];
printf("Enter any number :");
scanf("%s",num);
int len = strlen(num);
printf("The reverse of %s is",num);
for(int i = len - 1;i>=0;i--){
printf("%c",num[i]);
}
printf("\n");

return 0;
}