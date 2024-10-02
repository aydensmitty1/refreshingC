#include <stdio.h>

int main(){
    float pi, r, area;
    pi = 3.14;
    printf("What is radius of the circle in cm:\n");
    scanf("%f", &r);
    area = pi*(r*r);
    printf("The area of the circle is %f cm^2\n", area);
    return 0;
}