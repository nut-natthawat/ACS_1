#include <iostream>
using namespace std;

int padovan_naive2(int n){
    if(n < 3)
        return 1;
    if(n >= 3 && n < 5)
        return 2;
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 5; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    return dp[n];
}

int main(){
    int n = 8;
    cout << padovan_naive2(n);
}