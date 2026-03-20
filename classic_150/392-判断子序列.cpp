#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_it = 0, t_it = 0;
        while (s_it < s.size() && t_it < t.size()) {
            if (s[s_it] == t[t_it]) {
                s_it++;
            }
            t_it++;
        }
        return s_it == s.size();
    }
};