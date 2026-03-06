#include <iostream>
#include <map>
using namespace std;

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         unordered_map<int, bool> mp;
//         int max_num = *max_element(nums.begin(), nums.end());
//         for (const int i : nums) {
//             mp[i] = true;
//         }
//         for (int i = 1; i < max_num; i++) {
//             if (mp.find(i) == mp.end())
//                 return i;
//         }
//         if (max_num < 0) return 1;
//         return max_num + 1;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};