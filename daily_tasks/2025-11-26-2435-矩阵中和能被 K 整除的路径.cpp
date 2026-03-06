#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    const int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m);
        for (auto& i : dp) {
            i.resize(n);
            for (auto& j : i) {
                j.resize(k);
                for (auto& num : j) num = 0;
            }
        }
        dp[0][0][grid[0][0] % k] = 1;
        int sum = grid[0][0] % k;
        for (int i = 1; i < m; i++) {
            sum = (sum + grid[i][0]) % k;
            dp[i][0][sum] = 1;
        }
        sum = grid[0][0] % k;
        for (int j = 1; j < n; j++) {
            sum = (sum + grid[0][j]) % k;
            dp[0][j][sum] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int l = 0; l < k; l++) {
                    dp[i][j][(l + grid[i][j]) % k] = (dp[i][j][(l + grid[i][j]) % k] + dp[i-1][j][l] + dp[i][j-1][l]) % mod;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};

int main() {
    Solution sol;
    
    // 测试用例: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
    vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int k = 3;
    
    int result = sol.numberOfPaths(grid, k);
    cout << "测试用例: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3" << endl;
    cout << "结果: " << result << endl;
    
    // 验证路径和计算
    cout << "\n验证路径:" << endl;
    cout << "路径1: (0,0)->(0,1)->(0,2)->(1,2)->(2,2): 5+2+4+5+2 = 18, 18%3 = 0 ✓" << endl;
    cout << "路径2: (0,0)->(0,1)->(1,1)->(1,2)->(2,2): 5+2+0+5+2 = 14, 14%3 = 2 ✗" << endl;
    cout << "路径3: (0,0)->(0,1)->(1,1)->(2,1)->(2,2): 5+2+0+7+2 = 16, 16%3 = 1 ✗" << endl;
    cout << "路径4: (0,0)->(1,0)->(1,1)->(1,2)->(2,2): 5+3+0+5+2 = 15, 15%3 = 0 ✓" << endl;
    cout << "路径5: (0,0)->(1,0)->(1,1)->(2,1)->(2,2): 5+3+0+7+2 = 17, 17%3 = 2 ✗" << endl;
    cout << "路径6: (0,0)->(1,0)->(2,0)->(2,1)->(2,2): 5+3+0+7+2 = 17, 17%3 = 2 ✗" << endl;
    cout << "能被3整除的路径数: 2" << endl;
    
    return 0;
}