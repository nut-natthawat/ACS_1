#include <stdio.h>
int main(){
    int a[100],counteven=0,countodd=0,n;
    for(int i=1;;i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
        n++;
        if(a[i]<0){
            break;
        }
        n=i-1;
    }
    printf("Evennumber = ");
    for(int j=1;j<=n;j++){
        if(a[j]%2==0){
            printf("%d ",a[j]);
            counteven++;
        }
    }
    printf("\nTotal = %d numbers",counteven);
    printf("\nOddnumber = ");
    for(int j=1;j<=n;j++){
        if(a[j]%2!=0){
            printf("%d ",a[j]);
            countodd++;
        }
    }
    printf("\nTotal = %d numbers",countodd);
}