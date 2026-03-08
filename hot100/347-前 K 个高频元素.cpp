#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto item : mp) {
            pair<int, int> new_item = {item.second, item.first};
            pq.push(new_item);
        }
        vector<int> ret;
        while (k--) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    sol.topKFrequent(nums, 2);

    return 0;
}