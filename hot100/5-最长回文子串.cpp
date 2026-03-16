#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> dp;

    string longestPalindrome(string s) {
        if (s == "") return "";
        int max_len = 1;
        string ret = s.substr(0, 1);
        dp.resize(s.size());
        for (auto& line : dp) line.resize(s.size());

        for (int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i+1] = true;
                max_len = 2;
                ret = s.substr(i, 2);
            }
        }
        for (int len = 3; len <= s.size(); len++) {
            for (int l = 0; l + len - 1 < s.size(); l++) {
                int r = l + len - 1;
                if (dp[l+1][r-1] && s[l] == s[r]) {
                    dp[l][r] = true;
                    max_len = len;
                    ret = s.substr(l, len);
                }
            }
        }
        return ret;
    }
};