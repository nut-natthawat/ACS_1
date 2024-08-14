#include <stdio.h>
#include <conio.h>
void even(int num[],int size);
void odd (int num[],int size);
int main(){
    int size,num[20];
    printf("Enter number of elements (maximun 20 elements): ");
    scanf("%d",&size);
    printf("Enter all %d Array elements:\n",size);
    for(int i = 0;i<size;i++){
        scanf("%d",&num[i]);
    }
    even(num,size);
    odd(num,size);
}
void even(int num[],int size){
    int count=0;
    printf("\nAll even number are : ");
    for(int i = 0;i<size;i++){
        if((num[i] % 2)==0){
            printf(" %d ",num[i]);
        }
    }
}
void odd(int num[],int size){
    printf("\nAll odd number are :");
     for(int i = 0;i<size;i++){
        if((num[i] % 2)!=0){
            printf(" %d ",num[i]);
        }
    }
}