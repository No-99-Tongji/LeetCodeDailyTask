#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> go = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> vis;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vis.assign(m, vector<bool> (n, 0));

        vector<int> ret;
        int cur_dir = 0, x = 0, y = 0;
        while (ret.size() < m * n) {
            vis[x][y] = true;
            ret.push_back(matrix[x][y]);
            int dx = go[cur_dir].first, dy = go[cur_dir].second;
            int nx = x + dx, ny = y + dy;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n) || vis[nx][ny]) {
                cur_dir = (cur_dir + 1) % 4;
                dx = go[cur_dir].first, dy = go[cur_dir].second;
                nx = x + dx, ny = y + dy;
            }
            x = nx, y = ny;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    sol.spiralOrder(matrix);

    return 0;
}