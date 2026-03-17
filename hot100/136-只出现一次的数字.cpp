#include <vector>
using namespace std;

class Solution {
public:
    int cur = 0;
    int singleNumber(vector<int>& nums) {
        for (const int num : nums) cur ^= num;
        return cur;
    }
};