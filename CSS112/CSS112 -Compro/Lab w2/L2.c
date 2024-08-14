#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    printf("Please enter a value : ");
        scanf("%f",&a);
    printf("Please enter b value : ");
        scanf("%f",&b);
    printf("Please enter c value : ");
        scanf("%f",&c);
    double disciminant = (b*b)-(4*a*c);
    printf("Disciminant is %.3f\n",disciminant);
    double Root1 = (-b + (sqrt(disciminant)))/(2*a);
    double Root2 = (-b - (sqrt(disciminant)))/(2*a);
    printf("Frist Root is %.3f\nSecond Root is %.3f",Root1,Root2);
}