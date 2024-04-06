#include <stdio.h>
int main(){
    float num1,num2,num3,num4;
    printf("Input the values of four number : ");
    scanf("%f %f %f %f",&num1,&num2,&num3,&num4);
    printf("1st Number = %.2f\t2nd Number = %.2f\t3rd Number = %.2f\t4th Number = %.2f",num1,num2,num3,num4);
    if(num1 > num2 && num1 > num3 && num1 > num4){
        printf("\nThe 1st Nuumber is greatest among four");
    }
    else if (num2 > num1 && num2 > num3 && num2 > num4){
        printf("\nThe 2nd Nuumber is greatest among four");
    }
    else if (num3 > num1 && num3 > num2 && num3 > num4){
        printf("\nThe 3rd Nuumber is greatest among four");
    }
    else if (num4 > num1 && num4 > num2 && num4 > num3){
        printf("\nThe 4th Nuumber is greatest among four");
    }
}