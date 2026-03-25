#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pref, suf;

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        pref.resize(n); suf.resize(n);

        pref[0] = nums[0], suf[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) pref[i] = nums[i] * pref[i-1];
        for (int i = n-2; i >= 0; i--) suf[i] = nums[i] * suf[i+1];

        vector<int> ret(n);
        ret[0] = suf[1], ret[n-1] = pref[n-2];
        for (int i = 1; i < n - 1; i++) {
            ret[i] = pref[i-1] * suf[i+1];
        }
        return ret;
    }
};