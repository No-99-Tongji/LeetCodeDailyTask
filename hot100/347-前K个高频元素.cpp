#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
    unordered_map<int, int> mp;
public:
    bool cmp(pair<int, int> a, pair<int, int> b) {
        return b.second < b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (const int num : nums) {
            mp[num]++;
        }
        auto 
        priority_queue<pair<int, int>, vector<pair<int, int>>, >
    }
};