#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    stack<int> mono_stk;
    vector<int> left, right;
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        left.resize(n);
        right.resize(n);

        for (int i = 0; i < n; i++) {
            while (!mono_stk.empty() && heights[mono_stk.top()] >= heights[i]) {
                mono_stk.pop();
            }
            left[i] = (mono_stk.empty() ? -1 : mono_stk.top());
            mono_stk.push(i);
        }

        mono_stk = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!mono_stk.empty() && heights[mono_stk.top()] >= heights[i]) {
                mono_stk.pop();
            }
            right[i] = (mono_stk.empty() ? n : mono_stk.top());
            mono_stk.push(i);
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;
    sol.largestRectangleArea(heights);

    return 0;
}