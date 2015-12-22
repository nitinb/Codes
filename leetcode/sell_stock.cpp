#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices) {
    int current_max = 0, profit, max_profit = 0;
    std::vector<int> max (prices.size());
    for(int i = prices.size() - 1; i >= 0; i--) {
        max.at(i) = current_max;
        current_max = prices[i] > current_max ? prices[i] : current_max;
    }

    for(int i = 0; i < prices.size(); i++) {
        profit = max[i] - prices[i];
        max_profit = profit > max_profit ? profit : max_profit;
    }
    return max_profit;
}

int main() {
    Solution *sol = new Solution();
    std::vector<int> prices;
    prices.push_back(1);

    int num = sol->maxProfit(prices);
    std::cout << num << std::endl;
}