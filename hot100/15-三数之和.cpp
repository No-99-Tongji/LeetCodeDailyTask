#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = 1; k < n - 1; k++) {
            int i = 0, j = n - 1;
            while (i < k && k < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    if (set.find({nums[i], nums[k], nums[j]}) == set.end())
                    {
                        res.push_back({nums[i], nums[k], nums[j]});
                        set.insert({nums[i], nums[k], nums[j]});
                    }
                    i++;
                }
                else if (sum < 0) i++;
                else j--;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    auto res = sol.threeSum(nums);
    for (const auto& v : res) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << endl;
    }
}