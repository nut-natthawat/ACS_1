#include <stdio.h>
int main(){
    int  a_se,a_na,size,flag = 0;
    char name[100][50];
    char search;
    for(int i=1;;i++){
        printf("Iput name-surname :");
        gets(name[i]);
        size = i-1;
        if(name[i][0]=='*'){
            break;
        }
    }
    printf("=================================\n");
    printf("Input search char : "); 
    search = getchar();
    for(int i=0;i<=size;i++){
        a_se = search;
        a_na = name[i][0];
        if(a_na==a_se||a_na==a_se+32||a_na==a_se-32){
            flag++;
            printf("name %d is : %s\n",flag,name[i]);
        }
    }   
}