#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>

int diceRoll(){
    int randNum = rand() % 6;
    // printf("RandNum = %d\n", randNum);
    if (randNum == 0){
        randNum = diceRoll();
    }
    return randNum;
}

int main(){
    int balance = 1000;
    int guess = -1;
    int bet, result;

    while (guess != 0 || balance > 0){
        srand(rand());
        printf("Hello, your balance is: %d\n", balance);
        printf("Please Enter a bet:\n");
        scanf("%d", &bet);
        if (balance < bet){
            printf("Sorry you are better more than you have. We don't do credit here\n");
            continue;
        }
        printf("Now Enter a guess:\n");
        scanf("%d", &guess);
        if (guess == 0){
            printf("We are sorry to see you go, Hope you had a good time!\n");;
            break;
        }
        printf("We are sorry to see you go, Hope you had a good time!\n");
        printf("Rolling Dice...\n");
        Sleep(2);
        result = diceRoll();
        if (result == guess){
            printf("Nice Guess, You Won This Round!\n");
            balance = balance + (3*bet);
        }else if (guess != result){
            printf("Sorry, The Result was %d. Better Luck Next Time\n", result);
            balance = balance - bet;
        }
    }
    return 0;
}