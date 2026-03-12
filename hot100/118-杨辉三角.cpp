#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generateNewLine(const vector<int>& prev_line) {
        vector<int> newLine(prev_line.size() + 1);
        int n = newLine.size();
        for (int i = 0; i < n; i++) {
            newLine[i] = (i == 0 ? 0 : prev_line[i-1]) + (i == n-1 ? 0 : prev_line[i]);
        }
        return newLine;
    }

    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> ret;
        ret.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> line;
            const vector<int>& prev_line = ret.back();
            line = generateNewLine(prev_line);
            ret.push_back(line);
        }
        return ret;
    }
};