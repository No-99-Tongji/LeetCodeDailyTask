class Solution {
public:
    vector<vector<int>> C;

    int combine_num(int a, int b) {
        if (C[a][b]) return C[a][b];
        return C[a][b] = combine_num(a-1, b-1) + combine_num(a-1, b);
    }
    int uniquePaths(int m, int n) {
        C.resize(m + n + 1);
        for (int i = 0; i <= m + n; i++) {
            auto& line = C[i];
            line.resize(i + 1, 0);
            line[0] = line[i] = 1;
        }
        return combine_num(m + n - 2, n - 1);
    }
};