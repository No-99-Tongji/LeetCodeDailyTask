#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int m, n;
    void explore(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q) {
        pair<int, int> move[] = {{1,0},{0,1},{-1,0},{0,-1}};
        for (auto to : move) {
            int dx = to.first, dy = to.second;
            int nx = x + dx, ny = y + dy;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n) || grid[nx][ny] != 1) continue;
            grid[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        m = grid.size(), n = grid[0].size();
        bool sign = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) sign = false;
            }
        }
        if (sign) return 0;
        int result = -1;
        while (!q.empty()) {
            result++;
            int size = q.size();
            while (size--) {
                auto u = q.front();
                q.pop();
                int x = u.first, y = u.second;
                explore(grid, x, y, q);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return result;
    }
};