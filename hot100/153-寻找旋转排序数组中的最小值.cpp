class Solution {
public:
    int search(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = (l + r) / 2;
        if (nums[mid] >= nums[l]) {
            return min(nums[l], search(nums, mid+1, r));
        } else {
            return search(nums, l, mid);
        }
    }

    int findMin(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
};