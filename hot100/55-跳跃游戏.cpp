#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> canArr;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        canArr.resize(n);        
        canArr[n-1] = true;

        for (int i = n - 2; i >= 0; i--) {
            int jump = nums[i];
            bool flag = false;
            for (int j = i; j <= i + jump; j++) {
                if (canArr[j]) {
                    canArr[i] = true;
                    flag = true;
                    break;
                }
            }
            if (!flag) canArr[i] = false;
        }
        return canArr[0];
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    sol.canJump(nums);

    return 0;
}