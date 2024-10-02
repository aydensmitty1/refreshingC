#include <stdio.h>
#include <stdlib.h>


int maxOfThree(int a, int b, int c){
    return ((a > b ? a : b) > (b > c ? b : c) ? (a > b ? a : b) : (b > c ? b : c));
}

int main(){

    int a, b, c, max;
    a = 9;
    b = 11;
    c = 9;
    max = maxOfThree(a, b, c);
    printf("The Max of the three numbers is: %d", max);
    
    return 0;
}

