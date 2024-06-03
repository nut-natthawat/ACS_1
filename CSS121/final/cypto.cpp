#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

// ฟังก์ชันที่ใช้หากำไรสูงสุดจากการซื้อขาย 3 ครั้ง
tuple<int, vector<tuple<int, int, int>>> maxProfit(vector<int>& prices, int k) {
    int n = prices.size();
    int maxProfit = 0;
    vector<tuple<int, int, int>> bestTransactions;

    // ลองทุกความเป็นไปได้ของการซื้อขาย 3 ครั้ง
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int x = j + 1; x < n; x++) {
                for (int y = x + 1; y < n; y++) {
                    for (int p = y + 1; p < n; p++) {
                        for (int q = p + 1; q < n; q++) {
                            int profit1 = prices[j] - prices[i];
                            int profit2 = prices[y] - prices[x];
                            int profit3 = prices[q] - prices[p];
                            int totalProfit = profit1 + profit2 + profit3;
                            if (totalProfit > maxProfit) {
                                maxProfit = totalProfit;
                                bestTransactions = {{i, j, profit1}, {x, y, profit2}, {p, q, profit3}};
                            }
                        }
                    }
                }
            }
        }
    }

    return {maxProfit, bestTransactions};
}

int main() {
    vector<int> prices = {99, 2, 15, 17, 6, 35, 64, 10, 28, 32, 45, 11, 2, 36, 35, 44, 66, 9, 18, 24, 25, 98, 97, 11, 18, 2, 9, 19, 56, 12};
    int k = 3; // จำนวนครั้งที่สามารถซื้อขายได้

    auto [max_profit, transactions] = maxProfit(prices, k);

    cout << "max: " << max_profit << endl;
    for (const auto& trans : transactions) {
        cout << "buy: " << get<0>(trans) + 1 << " sell: " << get<1>(trans) + 1 
             << " kuy: " << get<2>(trans) << endl;
             << " kuy: " << get<2>(trans) << endl;
    }

    return 0;
}
