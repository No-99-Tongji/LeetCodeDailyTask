#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> line_mp, add_mp, sub_mp;
    vector<vector<bool>> mp;
    vector<vector<string>> ret;

    vector<string> toBoard() {
        vector<string> ret;
        for (auto& row : mp) {
            string line = "";
            for (bool i : row) {
                if (i) line += "Q";
                else line += "."
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
    }
};