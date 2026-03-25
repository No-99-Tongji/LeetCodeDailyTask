#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    vector<int> potentials;
    bool check(int p) {
        int sum = 0;
        int n = dp.size();
        for (int i = 0; i < n; i++) {
            sum += dp[p];
            p = (p + 1) % n;
            if (sum < 0) return false;
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 1) {
            if (gas[0] >= cost[0]) return 0;
            return -1;
        }
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < n; i++) {
            if (dp[(i - 1 + n) % n] < 0 && dp[i] >= 0) 
                potentials.push_back(i);
        }
        int sum = 0, ret;
        for (int p : potentials) {
            if (check(p)) return p;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {5};
    vector<int> cost = {4};
    sol.canCompleteCircuit(gas, cost);

    return 0;
}