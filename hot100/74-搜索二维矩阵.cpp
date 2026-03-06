#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l < r) {
            int x, y;
            int mid = (l + r + 1) / 2;
            x = mid / n, y = mid % n;
            int num = matrix[x][y];
            if (num > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return matrix[l / n][l % n] == target;
    }
};

int main() {
    vector<vector<int>> matrix = {
        { 1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };
    Solution sol;
    sol.searchMatrix(matrix, 3);

    return 0;
}