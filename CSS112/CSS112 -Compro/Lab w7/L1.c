#include <stdio.h>
int main(){
    int a[10],b[10],c[10],flag,n,m;
    printf("intput set a : ");
    printf("\n--------------------\n");
    for(int i=1;;i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
        n=i-1;
        if(a[i]<0){
            break;
        }
    }
    printf("Input set b :");
    printf("\n--------------------\n");
    for(int i=1;;i++){
        printf("b[%d] = ",i);
        scanf("%d",&b[i]);
        m=i-1;
        if(b[i]<0){
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                flag++;
                c[flag]=a[i];
            }
        }
    }
    if(flag!=0){
        printf("The intersection of set a and b : {");
        for(int i=1;i<=flag;i++){
            printf("%2d ",c[i]);
        }
        printf("}");
    }
    else if(flag==0){
        printf("The intersectino of set a nad b : { }");
    }
}