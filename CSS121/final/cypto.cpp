#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

// ฟังก์ชั่นสำหรับการคำนวณกำไรจากการซื้อและขายในแต่ละคู่
vector<tuple<int, int, int>> calculate_profit(const vector<int>& prices) {
    vector<tuple<int, int, int>> profits;
    int n = prices.size();
    for (int buy_day = 0; buy_day < n - 1; ++buy_day) {
        for (int sell_day = buy_day + 1; sell_day < n; ++sell_day) {
            int profit = prices[sell_day] - prices[buy_day];
            profits.emplace_back(profit, buy_day + 1, sell_day + 1);
        }
    }
    return profits;
}

int main() {
    vector<int> prices = {
        99, 2, 15, 17, 6, 35, 64, 10, 28, 32,
        45, 11, 2, 36, 35, 44, 66, 9, 18, 24,
        25, 98, 97, 11, 18, 2, 9, 19, 56, 12
    };

    // คำนวณกำไรทั้งหมดที่เป็นไปได้
    auto profits = calculate_profit(prices);
    // เรียงลำดับตามกำไรจากมากไปน้อย
    sort(profits.rbegin(), profits.rend());

    // เลือกการซื้อขาย 3 ครั้งที่ดีที่สุด
    vector<tuple<int, int, int>> best_trades;
    set<int> used_days;
    for (const auto& trade : profits) {
        int profit, buy_day, sell_day;
        tie(profit, buy_day, sell_day) = trade;
        if (used_days.count(buy_day) == 0 && used_days.count(sell_day) == 0) {
            best_trades.push_back(trade);
            used_days.insert(buy_day);
            used_days.insert(sell_day);
        }
        if (best_trades.size() == 3) {
            break;
        }
    }

    // แสดงผลลัพธ์
    for (const auto& trade : best_trades) {
        int profit, buy_day, sell_day;
        tie(profit, buy_day, sell_day) = trade;
        cout << "Buy on day " << buy_day << ", sell on day " << sell_day << ", profit: " << profit << endl;
    }

    return 0;
}
