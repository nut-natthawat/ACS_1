#include <stdio.h>
int main(){
    int x;
    printf("Input the size of array : ");
    scanf("%d",&x);
    int num[x];
    for(int i = 0;i<x;i++){
        printf("elements - %d : ",i);
        scanf("%d",&num[i]);
        for(int j=0;j<x-1;j++){
            for(int k = 0;k<x-j-1;k++){
                if(num[k] > num[k+1]){
                    int temp = num[k];
                    num[k] = num[k+1];
                    num[k+1] = temp;
            }
        }
    }
}
    for(int i = 0;i<x;i++){
        printf("%d  ",num[i]);
    }
}