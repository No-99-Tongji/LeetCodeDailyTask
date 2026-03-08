#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<char>> mp;
    vector<vector<bool>> vis;
    string _word;
    int rows, cols;
    vector<pair<int, int>> go = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool find(int pos, int x, int y) {
        if (mp[x][y] != _word[pos]) return false;
        if (pos == (int)_word.size() - 1) return true;
        vis[x][y] = true;
        for (auto to : go) {
            int nx = x + to.first, ny = y + to.second;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !vis[nx][ny]) {
                if (find(pos + 1, nx, ny))
                    return true;
            }
        }
        vis[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        mp = board;
        _word = word;
        rows = board.size();
        cols = board[0].size();
        vis.assign(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && find(0, i, j))
                    return true;
            }
        }
        return false;
    }
};