#include <map>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long result = 0;
        unordered_map<long long, long long> left;
        unordered_map<long long, long long> right;
        for (int i = 1; i < nums.size(); i++) {
            right[nums[i]]++;
        }
        left[nums[0]]++;
        for (int i = 1; i < nums.size() - 1; i++) {
            right[nums[i]]--;
            long long pro = left[nums[i]*2] * right[nums[i]*2];
            result = (result + pro) % mod;
            left[nums[i]]++;
        }
        return result;
    }
};