#include <stdio.h>

int isLeapYear(int year){
    return (year % 100 == 0 ? (year % 400 == 0 ? 1 : 0 ) : (year % 4 == 0 ? 1 : 0));
}

int main(){
    int year;
    printf("Please Enter a year!\n");
    scanf("%d", &year);
    if (isLeapYear(year)){
        printf("It is a leap year, RIBBIT!\n");
    }else{
        printf("Sorry, not a leap year...\n");
    }
}
