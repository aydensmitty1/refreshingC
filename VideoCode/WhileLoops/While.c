#include <stdio.h>
#include <string.h>

int main(){
char str[32];
int index = 0;
printf("Provide a String that contains the letter k:\n");
scanf("%s", &str);
int len = strlen(str);
while (str[index]!='k'){
    if (index >= len){
        printf("YOU DID NOT FOLLOW DIRECTIONS");
        return 0;
    }
    index++;
}
printf("The letter k is the %d letter in the string\n",index+1);
return 0;
}