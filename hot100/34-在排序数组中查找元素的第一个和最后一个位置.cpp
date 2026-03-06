#include <iostream>
#include <vector>
using namespace std;

class Solution { 
public:
    int rightEdge(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] <= target) {
                l = mid + 1;
            }
        }
        return l;
    }

    int leftEdge(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = leftEdge(nums, target);
        int r = rightEdge(nums, target);
        if (l <= r && nums[l] == target && nums[r] == target) return {l, r};
        else return {-1, -1};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    sol.searchRange(nums, 8);

    return 0;
}