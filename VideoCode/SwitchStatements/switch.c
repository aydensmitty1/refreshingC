#include <stdio.h>

int main(){
    int x;
    printf("Choose Between 1) apples, 2) pears, or 3) bananas.\n");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        printf("Great choice, I like apples too!\n");
        break;

    case 2:
        printf("Great choice, I like pears too!\n");
        break;

    case 3:
        printf("Great choice, I like bananas too!\n");
        break;

    default:
        printf("You Did Not Provide a Valid Answer!\n");
        break;
    }
    return 0;
}