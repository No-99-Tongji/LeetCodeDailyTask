#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = -INT_MAX;
        for (const int num : nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};