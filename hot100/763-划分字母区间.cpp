#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> min_pos, max_pos;

    vector<pair<int, int>> toPairs(unordered_map<char, int>& min_pos, unordered_map<char, int>& max_pos) {
        vector<pair<int, int>> ret;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto item : min_pos) {
            int l = item.second, r = max_pos[item.first];
            pq.push({l, r});
        }
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ret.empty() ? ret.push_back(top) : [&ret, top] () {
                auto end = ret.back();
                if (end.second >= top.first) {
                    ret.pop_back();
                    ret.push_back({min(end.first, top.first), max(end.second, top.second)});
                } else {
                    ret.push_back(top);
                }
            }();
        }
        return ret;
    }

    vector<int> partitionLabels(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (min_pos.find(s[i]) != min_pos.end()) {
                min_pos[s[i]] = min(min_pos[s[i]], i);
                max_pos[s[i]] = max(max_pos[s[i]], i);
            } else {
                min_pos[s[i]] = max_pos[s[i]] = i;
            }
        }
        auto pairs = toPairs(min_pos, max_pos);
        auto ret = [&pairs] () {
            vector<int> ret;
            for (const auto& pair : pairs) {
                ret.push_back(pair.second - pair.first + 1);
            }
            return ret;
        }();
        return ret;
    }
};

int main() {
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    sol.partitionLabels(s);

    return 0;
}