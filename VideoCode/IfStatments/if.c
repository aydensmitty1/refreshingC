#include <stdio.h>

int main(){

    int speed;
    printf("What is you speed at the moment?\n");
    scanf("%d", &speed);

    if (speed >= 85)
    {
        printf("You are goint to fast, Slow Down!");

    }else if (speed < 85 && speed >= 75)
    {
        printf("You are going a little fast, might want to slow down a little");

    }else if (speed < 75 && speed >= 40)
    {
        printf("Your speed is good, keep it up!");
    }
    else{
        printf("You are going too slow, speed up!");
    }
    return 0;
}