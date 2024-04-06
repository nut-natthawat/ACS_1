#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int d;
    int treex = rand() % 10;
    int treey = rand() % 10;
    for(int y=9;y>=0;y--){
        for(int x=0;x<=9;x++){
            if(y==8 && x==2){
                cout << "2" << " ";
                continue;
            }
            else if(y==0 && x==8){
                cout << "3" << " ";
                continue;
            }
            else if(y==treex && x==treey){
                cout << "1" << " ";
                continue;
            }
            cout << 0 << " " ; 
        }
        cout << "\n";
    }
    if(abs(8-2) > abs(0-8))d = abs(8-2);
    else d = abs(0-8);
    cout << "Taxicab = " << abs(8-2) + abs(0-8) << "\n";
    cout << "Euclidean = " << sqrt(pow(8-2,2)+pow(0-8,2)) << "\n";
    cout << "Chebyshev = " << d;
}