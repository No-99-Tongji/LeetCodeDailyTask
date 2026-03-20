#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= static_cast<int>(s.size())) return s;

        vector<string> rows(numRows);
        int row = 0;
        int dir = 1;  // 1: down, -1: up

        for (char c : s) {
            rows[row].push_back(c);
            if (row == 0) {
                dir = 1;
            } else if (row == numRows - 1) {
                dir = -1;
            }
            row += dir;
        }

        string ret;
        ret.reserve(s.size());
        for (const string& line : rows) {
            ret += line;
        }
        return ret;
    }
};