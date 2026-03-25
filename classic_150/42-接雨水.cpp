#include <vector>
using namespace std;

class Solution {
public:
    vector<int> left, right;
    int trap(vector<int>& height) {
        int n = height.size();
        left.resize(n); right.resize(n);

        left[0] = height[0], right[n-1] = height[n-1];
        for (int i = 1; i < n; i++) left[i] = max(left[i-1], height[i]);
        for (int i = n-2; i >= 0; i--) right[i] = max(right[i+1], height[i]);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += min(left[i], right[i]) - height[i];
        }
        return ret;
    }
};