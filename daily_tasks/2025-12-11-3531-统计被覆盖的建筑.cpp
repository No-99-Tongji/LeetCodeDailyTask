#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int result = 0;
        vector<int> min_row(n+1, n+1), max_row(n+1), min_line(n+1, n+1), max_line(n+1);

        for (const auto& p : buildings) {
            int x = p[0], y = p[1];
            min_row[y] = min(x, min_row[y]);
            max_row[y] = max(x, max_row[y]);
            min_line[x] = min(y, min_line[x]);
            max_line[x] = max(y, max_line[x]);
        }
        for (const auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x > min_row[y] && x < max_row[y] && y > min_line[x] && y < max_line[x]) result++;
        }
        return result;
    }
};

int main() {
    // vector<vector<int>> buildings = {{1,1}, {1,2}, {2,1}, {2,2}};
    vector<vector<int>> buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    Solution sol;
    sol.countCoveredBuildings(3, buildings);

    return 0;
}