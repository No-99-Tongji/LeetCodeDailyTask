#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret = 0;
        int prev = prices[0];
        for (int i = 1; i < n; i++) {
            int cur = prices[i];
            ret = max(ret, cur - prev);
            prev = min(prev, cur);
        }
        return ret;
    }
};