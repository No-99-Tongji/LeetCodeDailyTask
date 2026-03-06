#include <vector>
using namespace std;
class Solution {
public:
    vector<int> _nums;
    void permute(vector<vector<int>>& result, vector<int>& output, int first, int end) {
        if (first == end) {
            result.push_back(output);
            return;
        }
        output.push_back(_nums[first]);
        permute(result, output, first+1, end);
        output.pop_back();
        permute(result, output, first+1, end);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        _nums = nums;
        vector<vector<int>> result;
        vector<int> output;
        permute(result, output, 0, nums.size());
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.subsets(nums);

    return 0;
}