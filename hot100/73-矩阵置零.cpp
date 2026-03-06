#include <iostream>
using namespace std;

class Solution {
public:
    int ma;
    void change(vector<vector<int>>& matrix, int x, int y) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][y] != 0)
                matrix[i][y] = ma;
        }        
        for (int j = 0; j < n; j++) {
            if (matrix[x][j] != 0)
                matrix[x][j] = ma;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        ma = random();
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (matrix[i][j] == 0) change(matrix, i, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (matrix[i][j] == ma) matrix[i][j] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    sol.setZeroes(matrix);

    return 0;
}