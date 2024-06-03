#include <iostream>
#include <cstring>
using namespace std;

void sieveofEra(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime)); //ทำให้ทุกค่าเป็น true
    int p = 2;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    //print 
    cout << "Prime numbers less than or equal to " << n << " are:" << endl;
    for(int i=2 ; i<=n;i++){
        if(prime[i]==true){
            cout << i << " ";
        }
    }
}
int main(){
    int n = 30;
    sieveofEra(n);

}