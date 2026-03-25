#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                int k = n - 1 - i;
                swap(matrix[i][j], matrix[k][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j) continue;
                int x = j, y = i;
                swap(matrix[i][j], matrix[x][y]);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    sol.rotate(matrix);

    return 0;
}