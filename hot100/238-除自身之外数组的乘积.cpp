#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> prefix;
    vector<int> suffix;
    vector<int> productExceptSelf(vector<int>& nums) {
        prefix.resize(nums.size());
        suffix.resize(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }
        vector<int> result(nums.size(), 0);
        result[0] = suffix[1], result[nums.size()-1] = prefix[nums.size()-2];
        for (int i = 1; i < nums.size() - 1; i++) {
            result[i] = prefix[i-1] * suffix[i+1];
        }
        return result;
    }
};