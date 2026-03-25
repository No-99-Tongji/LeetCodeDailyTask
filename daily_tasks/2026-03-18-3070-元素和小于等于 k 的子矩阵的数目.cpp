#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sum;
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        sum.resize(m+1);
        int ret = 0;
        for (auto& line : sum) line.resize(n+1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i-1][j-1];
                ret += (sum[i][j] <= k);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {7, 6, 3},
        {6, 6, 1}
    };
    sol.countSubmatrices(grid, 18);

    return 0;
}