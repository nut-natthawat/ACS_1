#include<stdio.h>
int main(){
    int type;
    float area,rad,w,l,b,h;
    printf ("Input 1 for area of circle\n");
    printf("Input 2 for area of rectangle\n");
    printf("Input 3 for area of triangle\n");
    printf("Input your choice : ");
    scanf ("%d", &type);
    if (type==1){
        printf("Input radious of the circle: ");
        scanf("%f",&rad);
        area = 3.14* (rad*rad);
        printf("The area is : %.2f",area);
    }
    else if(type==2){
        printf("Input length and width of the rectangle: ");
        scanf("%f %f",&w,&l) ;
        area = w*l;
        printf("The area is : %.2f" ,area);
    }
    else if(type==3){
        printf("Input base and height of the triangle: ");
        scanf("%f %f",&b,&h);
        area = 1.0/2.0*b*h;
        printf("The area is : %.2f",area);
    }
}