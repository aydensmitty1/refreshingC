#include <stdio.h>
#include <assert.h>
#define F fflush(stdout)


void multi(int mult, int i){
    int result;
    result = mult * i;
    printf("%d X %d = %d\n", mult, i, result);
}


int main(){

    int mult;
    int product;
    printf("Please Select A Number from 1-12:\n"); F;
    scanf("%d", &mult);
    assert((mult < 13) && (mult > 0));

    for (int i = 0; i < 13; i++){
        multi(mult, i);

    }
    
    return 0;
}