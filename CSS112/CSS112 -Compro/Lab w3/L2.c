#include <stdio.h>
void function_net(int a);
int main (){
    char make[100],model[100];
    float cc,fee,es;
    int Nett;
    printf("What is your car make : ");
    gets(make);
    printf("What is your car model : ");
    gets(model);
    printf("Input the C.C. of your car : ");
    scanf("%f",&cc);
    printf("Annual Registration Fee Amount\n");
    printf("Car make : ");
    puts(make);
    printf("Car model : ");
    puts(model);
    printf("Engine Capacity (C.C.) : %.2f\n",cc);
    function_net(cc);
}

void function_net(int a){
    float fee,es;
    if(a <= 600){
        fee = a*0.5;
        es = 0;
    }
    else if (a>600 && a<=2000){
        fee = (600*0.5)+((a-600)*1.5);
        es = 0;
    }
    else if(a > 2000){
        fee = ((600*0.5)+((2000-600)*1.5))+((a-2000)*4);
        es = a * 0.25;
    }
        printf("Annual Registration Fee = %.2f\n",fee);
        printf("Emission Surchage Amount = %.2f\n",es);
        printf("Net Amount of Registration Fee : %.2f",fee+es);
}