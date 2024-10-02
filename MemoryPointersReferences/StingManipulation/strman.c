#include <stdio.h>
#include <stdlib.h>

//Function thar replaces the old char with a new char using pointer arithematic
void replaceChar(char *str, char oldChar, char newChar){
    //creates index variable
    int i = 0;
    //Traverses character string until it hits a 0/Null/end of string
    while (*(str + i) != 0){
        //If the character at that position is the same as old char
        if (*(str+i) == oldChar){
            // printf("%c -> %c\n", *(str+i), newChar);
            //Then it replaces old char at that pointer location to new char
            *(str+i) = newChar;
        }
        i++;
    }
    return;
}


int main(){
    //Creates starting variables
    char old, new;
    old = 'f';
    new = 'd';
    char str[] = "I really want a good fuck";

    printf("Old String: %s\n", str);
    //replaces all instacnes of old char
    replaceChar(str, old, new);

    printf("New String: %s\n", str);
} 