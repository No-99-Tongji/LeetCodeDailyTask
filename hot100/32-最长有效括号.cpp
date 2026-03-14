#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> dp;
    int longestValidParentheses(string s) {
        dp.resize(s.size());
        int ret = 0;
        for (auto& line : dp) line.resize(s.size(), 0);
        for (int i = 0; i + 1 < s.size(); i++) {
            dp[i][i+1] = s[i] == '(' && s[i+1] == ')';
            if (dp[i][i+1]) ret = 2;
        }

        for (int len = 4; len <= s.size(); len += 2) {
            for (int l = 0; l + len - 1 < s.size(); l++) {
                int r = l + len - 1;
                dp[l][r] = max({
                    dp[l+1][r-1] && s[l] == '(' && s[r] == ')', 
                    dp[l][r-2] && s[r-1] == '(' && s[r] == ')', 
                    dp[l+2][r] && s[l+1] == ')' && s[l] == '('
                });
                if (dp[l][r]) ret = max(ret, len);
            }
        }
        return ret;
    }
};

int main() {
    string s = ")(((((()())()()))()(()))(";
    Solution sol;
    sol.longestValidParentheses(s);

    return 0;
}