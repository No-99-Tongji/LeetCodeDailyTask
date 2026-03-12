class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 10000);
        dp[1] = 1;
        for (int i = 1; i * i <= n; i++)
        {
			dp[i * i] = 1;
		}
        for (int i = 2; i <= n; i++)
        {
            if (dp[i] == 1)
            {
				continue;
			}
            for (int j = 1; j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
};