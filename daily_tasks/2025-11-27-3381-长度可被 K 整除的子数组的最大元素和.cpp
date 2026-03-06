#include <iostream>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        long long result = LLONG_MIN;
        
        for (int start = 0; start < k; start++) {
            vector<long long> dp;
            
            for (int i = start; i <= n; i += k) {
                dp.push_back(prefix[i]);
            }
            
            if (dp.size() <= 1) continue;
            
            long long minPrefix = dp[0];
            for (int i = 1; i < dp.size(); i++) {
                result = max(result, dp[i] - minPrefix);
                minPrefix = min(minPrefix, dp[i]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr({-5,1,2,-3,4});
    cout << sol.maxSubarraySum(arr, 1) << endl;

    return 0;
}