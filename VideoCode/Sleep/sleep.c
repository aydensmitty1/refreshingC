#include <stdio.h>
#include <windows.h>

int main(){
    printf("Wait While Processing.........");
    fflush(stdout);
    Sleep(2);
    printf("ok\n");
}