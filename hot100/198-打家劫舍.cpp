#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp[2];
    int rob(vector<int>& nums) {
        dp[0].resize(nums.size()); dp[1].resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[0][i] = i == 0 ? 0 : max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = i == 0 ? nums[0] : dp[0][i-1] + nums[i];
        }
        return max(dp[0][nums.size()-1], dp[1][nums.size()-1]);
    }
};