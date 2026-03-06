#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (const int num : nums) pq.push(num);
        while (--k) pq.pop();
        return pq.top();
    }
};