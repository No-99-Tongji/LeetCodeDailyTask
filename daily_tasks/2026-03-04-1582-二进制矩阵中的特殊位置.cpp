#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rows, lines;
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) row.push_back(j);
            }
            rows.push_back(row);
        }
        for (int j = 0; j < n; j++) {
            vector<int> line;
            for (int i = 0; i < m; i++) {
                if (mat[i][j]) line.push_back(i);
            }
            lines.push_back(line);
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i].size() == 1 && rows[i][0] == j && lines[j].size() == 1 && lines[j][0] == i)
                    result++;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1,0,0},
        {0,0,1},
        {1,0,0}
    };

    Solution sol;
    sol.numSpecial(mat);

    return 0;
}