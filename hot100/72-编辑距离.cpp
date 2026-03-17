#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        dp.resize(m+1);
        for (auto& line : dp) line.resize(n+1);
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
                // else dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
        return dp[m][n];
    }
};