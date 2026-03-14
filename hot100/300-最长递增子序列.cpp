#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), 1);
        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    sol.lengthOfLIS(nums);

    return 0;
}