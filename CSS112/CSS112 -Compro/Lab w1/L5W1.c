#include<stdio.h>
#include<math.h>
int main(){
    double a = 8.3,b = 1,c = -2.6;
    double discriminant = b*b - 4*a*c;
    double Root1;
    double Root2;
    if(discriminant > 0){
        Root1 = (-b + (sqrt(discriminant)))/(2*a);
        Root2 = (-b - (sqrt(discriminant)))/(2*a);
        printf("for a = %.1f b = %.1f c = %.1f\nDiscriminant = %.3f\nRoot#1 = %.3f and Root#2 = %.3f",a,b,c,discriminant,Root1,Root2);
    }
    else{
        printf("Error");
    }

    return 0;
}