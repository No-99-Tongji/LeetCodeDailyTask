#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int dfs(int p, vector<int>& ratings) {
        int n = ratings.size();
        if (dp[p] != 1) return dp[p];
        if (p < n - 1 && ratings[p] > ratings[p+1]) dp[p] = max(dp[p], dfs(p+1, ratings) + 1);
        if (p > 0 && ratings[p] > ratings[p-1]) dp[p] = max(dp[p], dfs(p-1, ratings) + 1);
        return dp[p];
    }

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        dp.resize(n, 1);
        for (int i = 0; i < n; i++) dfs(i, ratings);
        int ret = 0;
        for (const int i : dp) ret += i;
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1,0,2};
    sol.candy(ratings);

    return 0;
}