#include <stdio.h>
int main(){
    int n,i;
    printf("Enter an integer: ");
    scanf("%d",&n);
    printf("Multiplication table of %d is: \n",n);
    for(i=1;i<=10;i++){
    printf("\n101%d*%d=%d",n,i,n*i);
    }
    return 0;
}