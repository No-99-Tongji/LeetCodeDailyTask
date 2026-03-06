#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<char>> _grid;
    int m, n;
    void dfs(int x, int y) {
        vis[x][y] = true;
        vector<pair<int, int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto to : move) {
            int dx = to.first, dy = to.second;
            int nx = x + dx, ny = y + dy;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n) || vis[nx][ny] || _grid[nx][ny] == '0') continue;
            dfs(nx, ny);
        }
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vis[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;   
    }

    int numIslands(vector<vector<char>>& grid) {
        _grid = grid;
        m = grid.size(), n = grid[0].size();
        vis.resize(m);
        for (auto& line : vis) line.resize(n);
        cout << vis.size() << ' ' << vis[0].size() << endl;
        int result = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && _grid[i][j] == '1') {
                    result++;
                    dfs(i, j);
                }
                // print();
            }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    sol.numIslands(grid);

    return 0;
}