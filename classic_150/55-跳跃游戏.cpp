#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> dp;

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1);

        dp[n] = true;
        for (int i = n-1; i >= 1; i--) {
            int gap = nums[i-1];
            for (int j = i; j <= i + gap && j <= n; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1};
    sol.canJump(nums);

    return 0;
}