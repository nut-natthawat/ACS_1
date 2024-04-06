#include <stdio.h>
#include <math.h>
int main(){
    int n,i,score[100];
    float x_bar,sd=0,sum=0;
    for(i=1;;i++){
        printf("score[%d] : ",i);
        scanf("%d",&score[i]);
        if(score[i]<0){
            break;
        }
    }
    n = i-1;
    for(i=1;i<=n;i++){
        sum += score[i];
    }
    x_bar = sum/n;
    for(i=1;i<=n;i++){
        sd += pow(score[i] - x_bar,2)/n;
    }
    sd = sqrt(sd);
    printf("==============================\n");
    printf("value of sd = %f",sd);
    printf("\n==============================");

}