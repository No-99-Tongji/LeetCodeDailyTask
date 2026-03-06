#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int m, n;

    bool check(int p, int threshold) {
        for (int i = 0; i+p <= m; i++) {
            for (int j = 0; j+p <= n; j++) {
                int sum = dp[i+p][j+p] - dp[i+p][j] - dp[i][j+p] + dp[i][j];
                if (sum <= threshold) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size(), n = mat[0].size();
        // cout << m << ' ' << n << endl;
        dp.resize(m+1);
        for (auto& line : dp)
            line.resize(n+1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        int l = 0, r = min(m, n);

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, threshold)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};