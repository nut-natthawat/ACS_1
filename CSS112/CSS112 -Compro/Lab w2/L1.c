#include <stdio.h>
int main(){
    int num,round;
    printf("Enter an integer : ");
    scanf("%d",&num);
    printf("Enter the range : ");
    scanf("%d",&round);
    for(int i=1;i<=round;i++){
        printf("%d * %d = %d\n",num,i,num*i);
    }
}