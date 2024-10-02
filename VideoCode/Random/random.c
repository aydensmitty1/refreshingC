#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int numgen(int max){
    int randNum = rand() % max;
    return randNum;
}

int main(){
    int random;
    srand(_getpid());
    // printf("%d\n", _getpid());
    random = numgen(10);
    printf("%d\n", random);
    return 0;
}