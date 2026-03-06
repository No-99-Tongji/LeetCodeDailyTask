#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<int> left_buy(k + 1, -prices[0]);
        vector<int> left_sell(k + 1, 0);
        vector<int> right_buy(k + 1, -prices[n-1]);
        vector<int> right_sell(k + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                left_buy[j] = max(left_buy[j], -prices[i] + left_sell[j - 1]);
                left_sell[j] = max(left_sell[j], prices[i] + left_buy[j]);
            }
        }
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
            {
                right_buy[j] = max(right_buy[j], -prices[i] + right_sell[j - 1]);
                right_sell[j] = max(right_sell[j], prices[i] + right_buy[j]);
            }
        }
        long long result = max(right_sell[0][k], left_sell[n-1][k]);
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j <= k; j++) {
                result = max(result, left_sell[i][j] + right_sell[i+1][k-j]);
            }
        }

        return sell[k];
    }
};