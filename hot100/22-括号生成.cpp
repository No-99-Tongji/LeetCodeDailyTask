#include <vector>
#include <string>
#include "iostream"
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> result;
    bool check(const string& str) {
        stack<char> sta;
        for (const char c : str) {
            if (c == '(') sta.push(c);
            else if (!sta.empty()) sta.pop();
            else return false;
        }
        return sta.empty();
    }
    void dfs(string& str, int idx, int n) {
        if (idx == n) {
            if (check(str)) result.push_back(str);
            return;
        }
        str += "(";
        dfs(str, idx+1, n);
        str.pop_back();
        str += ")";
        dfs(str, idx+1, n);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        dfs(str, 0, n*2);
        return result;
    }
};

int main() {
    Solution sol;
    auto result = sol.generateParenthesis(3);

    return 0;
}