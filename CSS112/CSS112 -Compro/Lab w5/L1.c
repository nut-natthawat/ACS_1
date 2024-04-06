#include <stdio.h>
int main(){
    int a,b;
    printf("Begin : ");
    scanf("%d",&a);
    printf("End : ");
    scanf("%d",&b);
    for(int i=1;i<=12;i++){
        for(int j=a;j<=b;j++){
            printf("%2d*%2d=%3d   ",j,i,j*i);
        }
        printf("\n");
    }
}