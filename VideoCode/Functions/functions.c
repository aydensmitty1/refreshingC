#include<stdio.h>

int triangle_area(int b, int h){
    int area;
    area = (b * h)/2;
    return area;
}

int main(){
    int b,h,area;
    printf("Please Provide a Base measurment of the triangle:\n");
    scanf("%d", &b);
    printf("Please Provide a Height measurment of the triangle:\n");
    scanf("%d", &h);
    area = triangle_area(b,h);
    printf("The area of the triangle is %d\n", area);
    return 0;
}