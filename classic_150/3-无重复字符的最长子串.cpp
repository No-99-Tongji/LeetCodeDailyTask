#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<char> st;
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int l = 0, r = 0, n = s.size();
        st.insert(s[l]);
        int ret = 1;
        while (r + 1 < n) {
            r++;
            while (st.count(s[r])) {
                st.erase(s[l++]);
            }
            cout << l << " " << r << endl;
            st.insert(s[r]);
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};