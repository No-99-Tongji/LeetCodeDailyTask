#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int m, n;

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (ans[x][y]) return ans[x][y];
        if (x == m-1 && y == n-1)
            return grid[x][y];
        int ret = 1000000000;
        // 只能向右或向下
        pair<int, int> go[2] = {{1, 0},{0, 1}};
        for (auto&[dx, dy] : go) {
            int nx = x + dx, ny = y + dy;
            if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n))
                ret = min(ret, dfs(nx, ny, grid));
        }
        return ans[x][y] = ret + grid[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        ans.resize(m);
        for (auto& line : ans) line.resize(n);
        return dfs(0, 0, grid);
    }
};