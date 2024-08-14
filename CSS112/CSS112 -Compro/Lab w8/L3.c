#include <stdio.h>
#include <conio.h>
int main(){
    int a[15]={8,5,4,9,11,18,10,12,16,17,15,30,25,13,19};
    int *pa,*pt,i,j,n=14;
    pa = &a[0];
    pt = &a[n];
    for(i=0;i<n/2;i++){
        *pt=*pt+*(pa+i);
        *pa += *pt;
        pa++;
        pt--;
    }
    pa = &a[7];
    for(j=1;j<=7;j++){
        printf("Line #%d :",j);
        printf("%5d%6d\n",*(pa-j),*(pa+j));
    }
}