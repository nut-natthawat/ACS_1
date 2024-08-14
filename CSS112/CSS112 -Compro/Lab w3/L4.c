#include<stdio.h>
int main(){
    int s1,s2,s3;
    printf("Input 1st side of triangle : ");
    scanf("%d",&s1);
    printf("Input 2nd side of triangle : ");
    scanf("%d",&s2);
    printf("Input 3rd side of triangle : ");
    scanf("%d",&s3);
    if(s1==s2 && s2==s3&& s1==s3){
        printf("This is an equilateral triangle");
}
    else if(s1==s2||s2==s3||s1==s3){
        printf("This is an isosceles triangle");
    }
    else{
        printf("This is an scalene triangle");
    }
}