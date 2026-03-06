#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> edge[161];
    
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        for (auto e : hierarchy) {
            int u = e[0], v = e[1];
            edge[u].push_back(v);
        }
    }
};