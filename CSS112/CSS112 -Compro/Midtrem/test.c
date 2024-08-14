#include <stdio.h>
#include <math.h>
/*
int main(){
    int dog_age,human_age;
    printf("Input your dog age : ");
    scanf("%d",&dog_age);
    if(dog_age >= 3){
        human_age = ((dog_age - 2)*4)+22;
    }
    else{
        human_age = dog_age*11;
    }
    printf("Your dog age to human age : %d year",human_age);
}*/

/*int main(){
    int num1,num2 ;
    int i,n = 0,min;
    printf("input number");
    scanf("%f %f",&num1,&num2);
    if(num1<num2){
        min = num1 ;
    }
    else if(num2 <num1){
        min = num2 ;
    }

    for(i=2;i<=min;i++){
        if( num1%i == 0 && num2%i == 0){
            n = i ;
        }
    }
    if(n!=0){
        printf("GCD is %d",n);
    }
    else if(n==0){
        printf("these number dont have GCD");
    }
    else if( num1==num2){
        printf("GCD is %d",num1);
    }
}*/
int add(int a,int b);
int main(){
    int result = add(23,32);
    printf("%d",result);
}
int add(int a,int b){
    return a+b;
}