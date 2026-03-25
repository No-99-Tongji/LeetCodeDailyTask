#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int min_steps(vector<int>& nums, int p) {
        if (dp[p] != 100000000) return dp[p];
        for (int i = p + 1; i <= p + nums[p] && i < nums.size(); i++) {
            dp[p] = min(dp[p], min_steps(nums, i) + 1);
        }
        return dp[p];
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, 100000000);
        dp[n-1] = 0;
        int ret =  min_steps(nums, 0);
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1};
    sol.jump(nums);

    return 0;
}