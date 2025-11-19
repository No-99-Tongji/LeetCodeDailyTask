#include <iostream>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos = -1;
        int len = nums.size();
        for (int i =0; i < len; i++) {
            if (nums[i] == 1) {
                if (pos == -1) {
                    pos = i;
                } else {
                    int dis = i - pos - 1;
                    pos = i;
                    if (dis < k) return false;
                }
            }
        }
        return true;
    }
};