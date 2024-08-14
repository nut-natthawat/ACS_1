#include <stdio.h>
float cal(float a,char opp,float b);
int main(){
    float num1,num2;
    char sign;
    printf("Input Express : ");
    scanf("%f %c %f",&num1,&sign,&num2);
    float output = cal(num1,sign,num2);
    printf("Output = %f",output);
}
float cal(float a,char opp,float b){
    if(opp =='+'){
        return a+b;
    }
    else if(opp == '-'){
        return a-b;
    }
    else if(opp =='*'){
        return a*b;
    }
    else if(opp =='/'){
        return a/b;
    }
}