#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        int res = 0;
        for (const int num : nums) {
            pre += num;
            if (mp.find(pre - k) != mp.end()) {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};
