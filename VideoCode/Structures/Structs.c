#include <stdio.h>
#include <string.h>

struct person
{   
    char title[8];
    char lastName[32];
    char firstName[32];
    int age;
};

int main(){
    struct person ayden;

    strncpy(ayden.title, "Mr.", 7);
    strncpy(ayden.lastName, "Smith",31);
    strncpy(ayden.firstName, "Ayden", 31);
    ayden.age = 22;

    printf("%s %s of the age %d\n", ayden.title, ayden.lastName, ayden.age);
    return 0;
}

