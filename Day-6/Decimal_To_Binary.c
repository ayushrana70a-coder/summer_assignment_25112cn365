# include <stdio.h>
int main () {
int num, b[10], i=0;
printf("Enter the decimal: ");
scanf(" %d", &num);
while (num > 0){
b[i++] = num % 2,
num /= 2;
}
printf ("Binary = ");
for(i=i-1; i>=0; i--){
printf("%d", b[i]);
}
return 0;
}
