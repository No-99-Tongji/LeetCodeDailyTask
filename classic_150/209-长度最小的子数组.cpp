#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prev;
    bool check(int target, int len, vector<int>& nums) {
        for (int l = 0; l + len - 1 < nums.size(); l++) {
            int r = l + len - 1;
            int sum = l == 0 ? prev[r] : prev[r] - prev[l-1];
            if (sum >= target) return true;
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        prev.resize(n);
        prev[0] = nums[0];
        for (int i = 1; i < n; i++) prev[i] = prev[i-1] + nums[i];
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(target, mid, nums)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (!check(target, l, nums)) return 0;
        return l;
    }
};