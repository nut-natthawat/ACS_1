#include <stdio.h>
#include <math.h>
void maxmin(int arr[],int n){
    float sum = 0;
    int min,max;
    for(int i = 0 ;i < n;i++){
        sum += arr[i];
        if(i == 0){
            max = min = arr[i];
        }
        else{
            if(arr[i]>max){
                max = arr[i];
            }
            if(arr[i]<min){
                min = arr[i];
            }
        }
    }
    double average = sum / n;
    printf("Maximun element : %d\n",max);
    printf("Minimun element : %d\n",min);
    printf("Average = %.2f",average);
}
int main(){
    int x;
    printf("Input the size of number : ");
    scanf("%d",&x);
    int num[x];
    float sum = 0;
    int max,min;
    for(int i=0;i<x;i++){
        printf("Enter number%d : ",i+1);
        scanf("%d",&num[i]);
    }
        maxmin(num,x);
}