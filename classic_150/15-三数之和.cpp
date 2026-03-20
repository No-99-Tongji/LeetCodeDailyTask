#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int prev = nums[i];
            int l = 0, r = n-1;
            while (l < r) {
                if (l == i) l++;
                if (r == i) r--;
                int sum = prev + nums[l] + nums[r];
                if (sum < 0) l++;
                else if (sum > 0) r--;
                else {
                    vector<int> to_insert = {nums[i], nums[l], nums[r]};
                    sort(to_insert.begin(), to_insert.end());
                    if (st.find(to_insert) == st.end()) {
                        ret.push_back(to_insert);
                        st.insert(to_insert);
                    }
                    break;
                }
            }
        }
        return ret;
    }
};