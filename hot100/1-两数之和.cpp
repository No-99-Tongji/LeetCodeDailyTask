class Solution {
public:
    vector<pair<int, int>> num_id;
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        num_id.resize(len);

        for (int i = 0; i < len; i++) {
            num_id.push_back({nums[i], i});
        }
        sort(num_id.begin(), num_id.end());
        int i = 0, j = 1;
        while (i < len) {
            int a = num_id[i].first, b = num_id[j].first;
            if (a + b == target) {
                return {num_id[i].second, num_id[j].second};
            }
            else if (a + b < target) {
                j++;
            }
            else {
                i
            }
        }
    }
};