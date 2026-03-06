class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) { // 注意这里是引用
            if (x == 2) {
                x = -1;
            } else {
                int t = ~x;
                x ^= (t & -t) >> 1;
            }
        }
        return nums;
    }
};