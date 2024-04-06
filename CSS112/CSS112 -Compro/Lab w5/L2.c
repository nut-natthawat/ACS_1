#include <stdio.h>
int main(){
    int a;
    printf("End : ");
    scanf("%d",&a);
    printf("  ");
    for(int i=1;i<=a;i++){
        printf("%4d",i);
    }
    printf("\n");
    for(int i=1;i<=a;i++){
        printf("%2d",i);
        for(int j=1;j<=i;j++){
            printf("%4d",i*j);
        }
        printf("\n");
    }
}