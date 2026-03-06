#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    set<vector<int>> set;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dp.resize(target+1);
        dp[0] = {{}};
        // for (int i = 0; i <= target; i++) dp[i] = {{}};
        int begin = candidates[0];
        for (int i = begin; i <= target; i++) {
            for (int num : candidates) {
                int pref = i - num;
                if (pref < 0) break;
                for (auto v : dp[pref]) {
                    vector<int> pre_vec = v;
                    pre_vec.push_back(num);
                    sort(pre_vec.begin(), pre_vec.end());
                    if (set.find(pre_vec) == set.end()) {
                        set.insert(pre_vec);
                        dp[i].push_back(pre_vec);
                    }
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> cand = {2,3,6,7};
    sol.combinationSum(cand, 7);

    return 0;
}