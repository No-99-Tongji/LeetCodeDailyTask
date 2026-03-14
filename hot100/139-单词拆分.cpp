#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> mp;
    vector<vector<bool>> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size());
        for (auto& line : dp) line.resize(s.size());
        for (const string& w : wordDict) mp[w] = true;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (mp[s.substr(i, j - i + 1)]) dp[i][j] = true;
            }
        } 
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (dp[i][j]) continue;
                for (int k = i; k < j; k++) {
                    if (dp[i][k] && dp[k+1][j] || k == j) dp[i][j] = true;
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    sol.wordBreak(s, wordDict);

    return 0;
}