#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <array>
using namespace std;
struct Transaction {
    int buyDay;
    int sellDay;
    int profit;
};
tuple<int, array<Transaction, 3>> maxProfit(const vector<int>& prices, int k) {
    int n = prices.size();
    int maxProfit = 0;
    array<Transaction, 3> bestTransactions;
    for (int i = 0; i < n; i++) { // ซื้อครั้งที่ 1
        for (int j = i + 1; j < n; j++) { // ขายครั้งที่ 1 ต้องเป็นวันที่หลังจากวันที่ซื้อครั้งแรก
            for (int x = j + 1; x < n; x++) { // ซื้อครั้งที่ 2 ต้องเป็นวันที่หลังจากวันที่ขายครั้งแรก
                for (int y = x + 1; y < n; y++) { // ขายครั้งที่ 2 ต้องเป็นวันที่หลังจากวันที่ซื้อครั้งที่สอง
                    for (int p = y + 1; p < n; p++) { // ซื้อครั้งที่ 3 ต้องเป็นวันที่หลังจากวันที่ขายครั้งที่สอง
                        for (int q = p + 1; q < n; q++) { // ขายครั้งที่ 3 ต้องเป็นวันที่หลังจากวันที่ซื้อครั้งที่สาม
                            int profit1 = prices[j] - prices[i]; // กำไร1
                            int profit2 = prices[y] - prices[x]; // กำไร2
                            int profit3 = prices[q] - prices[p]; // กำไร3
                            int totalProfit = profit1 + profit2 + profit3; 
                            if (totalProfit > maxProfit) { 
                                maxProfit = totalProfit; 
                                bestTransactions = {Transaction{i, j, profit1}, Transaction{x, y, profit2}, Transaction{p, q, profit3}}; // อัพเดตการซื้อขายที่ดีที่สุด
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
    int k = 3; 
    auto [max_profit, transactions] = maxProfit(prices, k);
    cout << "maxprofit: " << max_profit << endl;
    for (const auto& trans : transactions) {
        cout << "buy: " << trans.buyDay + 1 << " sell: " << trans.sellDay + 1 
             << " profit: " << trans.profit << endl;
    }
    return 0;
}
