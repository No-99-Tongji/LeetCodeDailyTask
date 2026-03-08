#include <vector>
using namespace std;

class Solution {
public:
    vector<int> jump_time;
    int jump(vector<int>& nums) {
        int n = nums.size();
        jump_time.resize(n, 100000000);
        jump_time[n-1] = 0;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j <= i + nums[i] && j < n; j++) {
                jump_time[i] = min(jump_time[i], jump_time[j] + 1);
            }
        }
        return jump_time[0];
    }
};