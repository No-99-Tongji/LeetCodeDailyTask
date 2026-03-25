#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp[2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp[0].resize(n+1, 0); dp[1].resize(n+1, 0);
        dp[1][0] = -100000000;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i-1]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i-1]);
        }
        return max(dp[0][n], dp[1][n]);
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    sol.maxProfit(prices);

    return 0;
}