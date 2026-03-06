#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> edge;
    vector<int> ind;
    vector<int> vis;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        ind.resize(numCourses);
        vis.resize(numCourses);
        for (auto& i : ind) i = 0;
        for (const auto& e : prerequisites) {
            int u = e[0], v = e[1];
            edge[v].push_back(u);
            ind[u]++;
        }
        queue<int> topoq;
        for (int i = 0; i < numCourses; i++) 
            if (ind[i] == 0) {
                topoq.push(i);
                vis[i] = true;
            }
        while (!topoq.empty()) {
            auto u = topoq.front();
            topoq.pop();
            for (int to : edge[u]) {
                ind[to]--;
                if (ind[to] == 0) {
                    topoq.push(to);
                    vis[to] = true;
                }
            }
        }
        for (const auto i : vis) if (!i) return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    sol.canFinish(2, prerequisites);

    return 0;
}