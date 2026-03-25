#include <vector>
using namespace std;

class Solution {
public:
    void super_swap(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l++], nums[r--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        super_swap(nums, n - k, n - 1);
        super_swap(nums, 0, n - k - 1);
        super_swap(nums, 0, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1};
    sol.rotate(nums, 2);

    return 0;
}