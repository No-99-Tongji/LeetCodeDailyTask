#include <iostream>
using namespace std;

class Solution {
public:
    pair<int, int> direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> vis;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0, x = 0, y = 0, m = matrix.size(), n = matrix[0].size();
        vis.resize(m);
        for (auto& line : vis) line.resize(n);
        vis[0][0] = true;
        vector<int> result;
        result.push_back(matrix[0][0]);
        while (true) {
            // cout << "x: " << x << " y: " << y << " dir: " << dir << endl;
            auto direct = direction[dir];
            int dx = direct.first, dy = direct.second;
            int nx = x + dx, ny = y + dy;
            // if (nx == 0 && ny == 4) {
            //     cout << "here" << endl;
            // }
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n) || vis[nx][ny] == true) {
                dir = (dir + 1) % 4;
                direct = direction[dir];
                int dx = direct.first, dy = direct.second;
                cout << "dx: " << dx << " dy: " << dy << endl;
                cout << "direct.first: " << direct.first << " direct.second: " << direct.second << endl;
                int nx = x + dx, ny = y + dy;
                cout << "nx: " << nx << " ny: " << ny << endl;
                if (!(nx >= 0 && nx < m && ny >= 0 && ny < n) || vis[nx][ny]) break;
            }
            vis[nx][ny] = true;
            result.push_back(matrix[nx][ny]);
            x = nx, y = ny;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    sol.spiralOrder(mat);

    return 0;
}