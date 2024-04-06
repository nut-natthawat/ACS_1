#include <stdio.h>
int main(){
    int a,j;
    printf("End : ");
    scanf("%d",&a);
    printf("  ");
    for(int i=1;i<=a;i++){
        printf("%4d",i);
    }
    for(int i=1;i<=a;i++){
        printf("\n%2d",i);
        for(j=1;j<=a-i;j++){
            printf("    ");
        }
        for(j=j;j<=a;j++){
            printf("%4d",i*j);
        }
    }
}