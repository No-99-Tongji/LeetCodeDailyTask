#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int l = 0, r = 0, n = s.size();
        int res = 0;
        while (l < n && r < n) {
            cout << l << ' ' << r << endl;
            if (set.find(s[r]) == set.end() || l == r) {
                set.insert(s[r]);
                res = max(res, r-l+1);
                cout << res << endl;
                r++;
            }
            else {
                set.erase(s[l]);
                l++;
                set.insert(s[l]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s) << endl;
}