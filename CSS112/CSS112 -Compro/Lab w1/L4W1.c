#include <stdio.h>
#include <math.h>
int main(){
    double num[] = {2.00,4.00,6.00,8.00,10.00};
    double sum = 0;
    double range = sizeof(num)/sizeof(num[0]);
    for(int i = 0;i < range;i++ ){
        sum = sum+(1/num[i]);
    }
    printf("Harmonic Mean of 2.00,4.00,6.00,8.00 and 10.00 = %.3f",range/sum);

    return 0;
}