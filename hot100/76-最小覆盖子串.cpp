#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> base;
    unordered_map<char, int> mp;
    bool check() {
        for (auto& item : base) {
            if (mp[item.first] < item.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        for (const char c : t) base[c]++;

        string result;
        int min_len = INT_MAX;

        int l = 0, r = 0;
        mp[s[0]] = 1;
        while (r < s.length()) {
            if (check() && min_len > r - l + 1) {
                result = s.substr(l, r - l + 1);
                min_len = r - l + 1;
            }
            if (mp[s[l]] > base[s[l]]) {
                mp[s[l]]--;
                l++;
            }
            else {
                r++;
                mp[s[r]]++;
            }
            // cout << s.substr(l, r - l + 1) << endl;
            // if (s.substr(l, r - l + 1) == "BECODEBA") cout << mp[s[l]] << endl;
        }
        return result;
    }
};

int main() {
    Solution sol;
    sol.minWindow("ab", "a");
}