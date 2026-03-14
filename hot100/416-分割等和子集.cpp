#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<int> st;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if ((sum & 1) == 1) return false;
        for (const int num : nums) {
            vector<int> temp;
            for (auto item : st) {
                temp.push_back(item + num);
            }
            for (auto item : temp) {
                st.insert(item);
            }
            st.insert(num);
        }
        return st.find(sum >> 1) != st.end();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,5,11,5};
    sol.canPartition(nums);

    return 0;
}