#include <stdio.h>
int main(){
    char a[100],n;
    printf("Input name-surname : ");
    gets(a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' '){
            n=i;
            break;
        }
    }
    for(int i=n+1;a[i];i++){
        printf("%c",a[i]);
    }
    printf(" ");
    for(int i=0;i<=n;i++){
        printf("%c",a[i]);
    }
}