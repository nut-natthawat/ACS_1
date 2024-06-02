#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ฟังก์ชั่นสำหรับการคำนวณกำไรสูงสุดด้วย Dynamic Programming
int maxProfitWithKTransactions(const vector<int>& prices, int k) {
    int n = prices.size();
    if (n == 0) return 0;

    // สร้างตาราง dp
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int t = 1; t <= k; ++t) {
        int maxDiff = -prices[0];
        for (int d = 1; d < n; ++d) {
            dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
            maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
        }
    }

    return dp[k][n - 1];
}

int main() {
    vector<int> prices = {
        99, 2, 15, 17, 6, 35, 64, 10, 28, 32,
        45, 11, 2, 36, 35, 44, 66, 9, 18, 24,
        25, 98, 97, 11, 18, 2, 9, 19, 56, 12
    };

    int k = 3; // จำนวนครั้งของการซื้อขายที่อนุญาต
    int maxProfit = maxProfitWithKTransactions(prices, k);

    cout << "Maximum profit with " << k << " transactions: " << maxProfit << endl;

    return 0;
}
