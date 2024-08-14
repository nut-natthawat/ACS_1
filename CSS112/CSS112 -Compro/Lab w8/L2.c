#include <stdio.h>
int main(){
    int a[100],b[100],c[100],i,*Pa,*Pb,*Pc,n=0,sizea=0,sizeb=0,flag=0;
    Pa = &a[1];
    Pb = &b[1];
    printf("input set a : ");
    printf("\n------------------------\n");
    for(i=1;;i++){
        printf("a[%d] = ",i);
        scanf("%d",Pa);
        if(*Pa<0){
            break;
        }
        sizea++;
        Pa++;
    }
    printf("======================\n");
    printf("input set b : ");
    printf("\n-----------------\n");
    for(i=1;;i++){
        printf("b[%d] = ",i);
        scanf("%d",Pb);
        if(*Pb<0){
            break;
        }
        sizeb++;
        Pb++;
    }
    Pa = &a[1];
    Pb = &b[1];
    Pc = &c[1];
    for(i=0;i<=sizea;i++){
        flag = 0;
        for(int j=0;j<=sizeb;j++){
            if(*Pa == *Pb){
                flag = 1;
                break;
            }
            Pb++;
        }
        if(flag == 0){
            *Pc = *Pa;
            n++;
            Pc++;
        }
        Pa++;
        Pb = &b[1];
    }
    Pc = &c[1];
    printf("A - B = ");
    for(i=1;i<=n;i++){
        printf("%d ",*Pc);
        Pc++;
    }
}