#include <stdio.h>
int f(int a);
int main(){
    int n;
    printf("Input n :");
    scanf("%d",&n);
    printf("Output f(%d) = %d",n,f(n));
}
int f(int a){
    if (a == 0) return 1;
    else if (a >= 1 && a <= 2) return 2;
    else return (f(a-1)+f(a-2));
}