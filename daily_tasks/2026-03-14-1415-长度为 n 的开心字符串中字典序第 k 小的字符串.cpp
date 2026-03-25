#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ret;
    void dfs(const string& cur, int n, int pos) {
        if (pos == n) {
            ret.push_back(cur);
            return;
        } 
        for (char c : {'a', 'b', 'c'}) {
            if (cur.empty() || c != cur.back()) {
                string new_str = cur + string(1, c);
                dfs(new_str, n, pos + 1);
            }
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        dfs(s, n, 0);
        if (k > ret.size()) return "";
        return ret[k-1];
    }
};

int main() {
    Solution sol;
    sol.getHappyString(1, 3);

    return 0;
}