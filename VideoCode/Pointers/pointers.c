#include <stdio.h>
#include <string.h>

int main(){

    char str[32];
    char *p;

    strncpy(str, "I like fruits", 31);
    p = str;
    printf("%s\n", p);
    p = p + 1;
    printf("%s\n", p);
    p = p + 1;
    printf("%c\n", *p);
    return 0;
}