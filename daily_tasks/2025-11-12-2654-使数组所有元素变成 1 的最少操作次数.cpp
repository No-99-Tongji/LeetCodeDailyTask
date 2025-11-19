#include <iostream>
#include <numeric> 
using namespace std;

class Solution {
public:

    int minOperations(vector<int>& nums) {
        int min_dis = INT_MAX;
        const int len = nums.size();
        const int one_num = [&nums] () {
            int res = 0;
            for (const int num : nums) res += (num != 1);
            return res;
        }();
        for (int i = 0; i < len; i++) {
            int base = nums[i];
            for (int j = i + 1; j < len; j++) {
                if ((base = gcd(base, nums[j])) == 1) 
                    min_dis = min(min_dis, j - i);
            }
        }
        if (min_dis == INT_MAX) return -1;
        return min_dis + one_num - 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {410193,229980,600441};
    cout << sol.minOperations(nums) << endl;

    return 0;
}