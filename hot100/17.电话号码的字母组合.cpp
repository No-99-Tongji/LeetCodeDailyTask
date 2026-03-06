#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> mp;

    void perm(vector<string>& result, string& output, int first, int end) {
        if (first == end) {
            result.push_back(output);
            return;
        }
        for (int i = 0; i < mp[first].size(); i++) {
            output.push_back(mp[first][i]);
            perm(result, output, first+1, end);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> _mp = {
            {},
            {},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
        };
        for (const char c : digits) {
            mp.push_back(_mp[c-'0']);
        }
        
        vector<string> result;
        string output;
        perm(result, output, 0, digits.size());
        return result;
    }
};

int main() {
    Solution sol;
    sol.letterCombinations("23");

    return 0;
}