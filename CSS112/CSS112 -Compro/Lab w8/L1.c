#include <stdio.h>
int main(){
    int num[100]={0},*p,i,n,flag=0,gcd=0;
    p = &num[1];
    printf("intput array a: ");
    printf("\n---------------------------------\n");
    for(i=1;;i++){
        printf("a[%d] = ",i);
        scanf("%d",p);
        if(*p<0){
            break;
        }
        p++;
    }
    n = i-1;
    p = &num[1];
    int min = *p;
    for(i=1;i<n;i++){
        if(min>*p){
            min = *p;
        }
        p++;
    }
    for(i = min;i>=1;i--){
        p = &num[1];
        for(int j=1;j<=n;j++){
            if(*p % i == 0){
                flag=1;
            }
            else if(*p % i != 0){
                flag = 0;
                break;
            }
            p++;
        }
        if(flag == 1){
            gcd = i;
            break;
        }
    }
    printf("The GCD = %d",gcd);
}