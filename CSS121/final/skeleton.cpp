#include <iostream>
#include <string>
using namespace std;
void longestcommon(string X,string Y,int m,int n){
    int L[m + 1][n + 1];

    // สร้างตาราง L[m+1][n+1] แบบ Bottom-up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = m ,j = n;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    //print
    cout << "LCS of " << X << " and " << Y << " is " << lcs << " Lenght is " << L[m][n] << endl;
}

int main(){
    int m = 15;
    int n = 15;
    string X_1 = "TGCTACTCCACACAC";
    string X_2 = "TAGTACTCCACACAC";
    string X_3 = "TGCTACTGCAGACAC";
    string X_4 = "TACTACTGCACCCAC";
    string X_5 = "TAGCACTCCAGACCC";
    
    longestcommon(X_1,X_2,m,n);
    longestcommon(X_1,X_3,m,n);
    longestcommon(X_1,X_4,m,n);
    longestcommon(X_1,X_5,m,n);
    longestcommon(X_2,X_3,m,n);
    longestcommon(X_2,X_4,m,n);
    longestcommon(X_2,X_5,m,n);
    longestcommon(X_3,X_4,m,n);
    longestcommon(X_3,X_5,m,n);
    longestcommon(X_4,X_5,m,n);
}
