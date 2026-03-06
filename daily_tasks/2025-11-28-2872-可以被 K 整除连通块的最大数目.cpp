#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> edge;
    vector<int> value;
    long long res = 0;
    long long mod;
    long long dfs(int p, int fa) {
        long long sum = value[p];
        for (const auto to : edge[p]) {
            if (to == fa) continue;
            long long num = dfs(to, p);
            if (p == 2 && to == 1) cout << endl << num << endl;
            if (num % mod == 0) res++;
            sum += num;
        }
        cout << "Node " << p << ": " << sum << endl;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        value = values;
        mod = k;
        edge.resize(n);
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for (int i = 0; i < edge.size(); i++) {
            cout << i << ": ";
            for (const int to : edge[i]) {
                cout << to << ' ';
            }
            cout << endl;
        }
        dfs(0, 0);
        return res + 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};

    cout << sol.maxKDivisibleComponents(5, edges, values, 6) << endl;

    return 0;
}