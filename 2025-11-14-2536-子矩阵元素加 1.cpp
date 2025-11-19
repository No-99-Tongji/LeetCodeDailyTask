#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> diff;

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        diff.resize(n+1);
        for (auto& row : diff) row.resize(n+1);

        for (const auto& q : queries) {
            int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i-1][j];
                int x2 = (j == 0) ? 0 : mat[i][j-1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i-1][j-1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
};