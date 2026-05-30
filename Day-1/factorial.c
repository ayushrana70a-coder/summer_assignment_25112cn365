#include <stdio.h>
int main(){
int n,i,factorial=1;
printf("Enter an integer: ");
scanf("%d",&n);
if(n<0){
    printf("factorial doesn't exist");
    } else {
    for(i=1;i<=n;i++){
        factorial*=i;
    }
    printf("factorial of %d is %d",n,factorial);
    }
    return 0;


}