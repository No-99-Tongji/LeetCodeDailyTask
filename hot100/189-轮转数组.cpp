#include <iostream>
using namespace std;

class Solution {
public:
    void super_swap(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++, end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        super_swap(nums, 0, nums.size() - k - 1);
        super_swap(nums, nums.size() - k, nums.size() - 1);
        super_swap(nums, 0, nums.size() - 1);
    }
};