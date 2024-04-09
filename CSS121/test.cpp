#include <iostream>
using namespace std;

double partition(int arr[],int l,int r){
    int x = arr[r],i = l;
    for(int j = l;j<=r-1;j++){
        if(arr[j] <= x){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
double kthsmallest(int arr[],int l,int r,int k){
    if(k > 0 && k <= r - l + 1){
        int index = partition(arr,l,r);
        if(index - l == k - 1){
            return arr[index];
        }
        if(index - l > k - 1){
            return kthsmallest(arr,l,index - 1,k);
        }else{
            return kthsmallest(arr,index+1,r,k-index+l-1);
        }
    }
    return INT_MAX;
}

double median(int arr[], int l, int r) {
    int n = r - l + 1;
    int k = (n % 2);
    if(k == 0){
        k = n/2;
    }else{
        k = n/2+1;
    }
    double median1 = kthsmallest(arr, l, r, k);
    if (n % 2 == 1)
        return median1;
    
    double median2 = kthsmallest(arr, l, r, k + 1);
    return (median1 + median2) / 2.0;
}


int main(){
    int arr[100]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Median number is :" << median(arr,0,n-1);
}