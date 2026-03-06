#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        result.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i - q.front() >= k) q.pop_front();
            result.push_back(nums[q.front()]);
        }
        for (const int i : result) cout << i << ' ';
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    sol.maxSlidingWindow(vec, 3);
}