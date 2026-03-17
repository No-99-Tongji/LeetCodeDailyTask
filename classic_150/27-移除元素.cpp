#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) k++;
            else {
                nums[i-k] = nums[i];
            }
        }
        return nums.size() - k;
    }
};