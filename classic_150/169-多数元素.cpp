#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum = 0;
        int ret = nums[0];
        for (int num : nums) {
            if (num == ret) sum++;
            else sum--;
            if (sum < 0) {
                sum = 1;
                ret = num;
            }
        }
        return ret;
    }
};