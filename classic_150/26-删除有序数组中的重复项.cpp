#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<int> st;
    int removeDuplicates(vector<int>& nums) {
        int rm_num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            } else {
                rm_num++;
            }
            nums[i-rm_num] = nums[i];
        }
        return nums.size() - rm_num;
    }
};