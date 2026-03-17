#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int prev = -100000000;
        int n = nums.size();
        int i = n-1;
        for (; i >= 0; i--) {
            if (nums[i] < prev) break;
            else prev = nums[i];
        }

        if (i >= 0) {
            int j = n-1;
            for (; j >= i; j--) {
                if (nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};