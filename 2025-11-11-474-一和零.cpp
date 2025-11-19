#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    void init(int m, int n) {
        dp.resize(m+1);
        for (auto& v : dp) v.resize(n+1);
        for (auto& l : dp)
            for (auto& v : l)
            v = 0;
    }

    int count_one(const string& str) {
        int res = 0;
        for (const auto c : str) res += (c == '1');
        return res;
    }

    int count_zero(const string& str) {
        int res = 0;
        for (const auto c : str) res += (c == '0');
        return res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        init(m, n);
        int siz = strs.size();

        for (int k = 0; k < siz; k++) {
            int one_num = count_one(strs[k]);
            int zero_num = count_zero(strs[k]);
            for (int i = m; i >= zero_num; i--) {
                for (int j = n; j >= one_num; j--) {
                    dp[i][j] = max(dp[i-zero_num][j-one_num] + 1, dp[i][j]);
                }
            }        
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    cout << dp[i][j] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    // cout << sol.findMaxForm(strs, 1, 1) << endl;
    sol.findMaxForm(strs, 5, 3);

    return 0;
}