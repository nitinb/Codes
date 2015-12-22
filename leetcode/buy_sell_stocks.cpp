#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices) {
    bool bought = false;
    int bought_price, profit = 0, x = prices.size();

    for(int i = 0; i < x - 1; i++) {
        if(bought && bought_price < prices[i]) {
            profit = profit + (prices[i] - bought_price);
            bought = false;
        }

        if(!bought) {
            if(prices[i] < prices[i+1]) {
                bought = true;
                bought_price = prices[i];
            }
        }
    }

    if(bought) {
        profit = profit + (prices[prices.size()-1] - bought_price);
        bought = false;
    }
    
    return profit;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {1, 2, 3};
    std::vector<int> prices (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    int num = sol->maxProfit(prices);
    std::cout << num << std::endl;
}
    
    