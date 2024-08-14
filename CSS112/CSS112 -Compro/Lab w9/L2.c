#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 
int dec(char a[100],int radix);
int main(){
    char num[100]={0};
    int r,result;
    printf("Input number : ");
    gets(num);
    printf("Numer is base : ");
    scanf("%d",&r);
    result = dec(num,r);
    printf("Number is decimal : %d",result);
}
int dec(char a[100],int radix){
    int n,i,d,sum=0;
    char x[2];
    n= strlen(a);
    for(i=n-1;i>=0;i--){
        x[0] = a[i];
        int b = x[0];
        if(b <= 70 && b >= 65){
            d = b-55;
        }
        else{
            d = atoi(x);
        }
        sum += d*pow(radix,n-i-1);
    }
    return sum;
}