#include <iostream>
#include <vector>
using namespace std;
struct Row
{
    int A;
    int B;
    int C;
};

void insertionsort(std::vector<Row>&arr, int n,char columm){
    int i,j;
    for (i = 1; i < n; i++) {
        Row key = arr[i];
        switch (columm) {
            case 'A':
                for (j=1;j > 0 && arr[j - 1].A > key.A;j--) {
                    arr[j+1] = arr[j];
                }
                arr[j+1] = key.A;
            case 'B':
                for (j=1;j > 0 && arr[j - 1].B > key.B;j--) {
                    arr[j+1] = arr[j];
                }
                arr[j+1] = key.B;
            case 'C':
                for (j=1;j > 0 && arr[j - 1].C > key.C;j--) {
                    arr[j+1] = arr[j];
                }
                arr[j+1] = key.C;
            default:
                break;
        }
        arr[j] = key;
    }
}
int main(){
    int n = 15;
    std::vector<Row> data ={
        {1,1,4},
        {3,1,1},
        {4,4,4},
        {2,4,4},
        {3,5,3},
        {4,3,3},
        {1,3,3},
        {2,4,3},
        {3,3,5},
        {1,5,3},
        {1,1,4},
        {4,1,1},
        {5,2,3},
        {3,5,2}
    };
    char columm;
    cout << "Input columm to sort (A,B,C) : ";
    cin >> columm;
    insertionsort(data,n,columm);
    for(const Row& row : data){
        cout << row.A << " " << row.B << " " << row.C << endl;
    }
}