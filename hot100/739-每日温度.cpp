#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() == 0) return {0};
        stack<pair<int, int>> temp_id;
        vector<int> ret(temperatures.size());
        temp_id.push({temperatures[0], 0});
        for (int i = 1; i < temperatures.size(); i++) {
            while (!temp_id.empty()) {
                const auto& top = temp_id.top();
                int temperature = top.first, id = top.second;
                if (temperatures[i] > temperature) {
                    temp_id.pop();
                    ret[id] = i - id;
                } else break;
            }
            temp_id.push({temperatures[i], i});
        }
        while (!temp_id.empty()) {
            const auto& top = temp_id.top();
            temp_id.pop();
            int temperature = top.first, id = top.second;
            ret[id] = 0;
        }
        return ret;
    }
};