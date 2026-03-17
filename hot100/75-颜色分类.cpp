#include <vector>
using namespace std;

class Solution {
public:
    int _nums[3];
    void sortColors(vector<int>& nums) {
        for (const int num : nums) _nums[num]++;
        nums.clear();
        for (int i = 0; i < 3; i++) {
            while (_nums[i]--) {
                nums.push_back(i);
            }
        }
    }
};