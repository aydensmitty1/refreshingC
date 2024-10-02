#include <stdio.h>

int main(){
    int x,y,sum;

    printf("Please Provide a Number:\n");
    scanf("%d", &x);
    printf("Please Provide Another Number:\n");
    scanf("%d", &y);
    sum = x + y;
    printf("The Sum of these numbers is %d\n", sum);
    return 0;
}