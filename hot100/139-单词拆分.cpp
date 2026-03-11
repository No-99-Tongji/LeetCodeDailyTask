#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<string>> hash_slots;

    int hash(const string& s) {
        return s.length();
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (const string& w : wordDict) {
            hash_slots[hash(w)].push_back(w);
        }

        while (s.length()) {
            bool flag1 = false;
            for (int i = 1; i <= 20; i++) {
                bool flag2 = false;
                if (hash_slots.find(i) == hash_slots.end()) continue;
                for (const string& w : hash_slots[i]) {
                    if (s.substr(0, i) == w) {
                        s = s.substr(i);
                        flag2 = true;
                        break;
                    }
                }
                if (flag2) {
                    flag1 = true;
                    break;
                }
            }
            if (!flag1) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    sol.wordBreak(s, wordDict);

    return 0;
}