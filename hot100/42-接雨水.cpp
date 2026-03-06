#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int dis = i - left - 1;
                int h = min(height[i], height[left]) - height[top];
                ans += dis * h;
            }
            stk.push(i);
        }
        return ans;
    }
};