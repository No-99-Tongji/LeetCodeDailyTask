#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        int n = [&strs] () {
            int ret = 100000000;
            for (const auto& s : strs) ret = min(ret, (int)s.size());
            return ret;
        }();
        int iter = 0;
        while (iter < n) {
            if ([&strs, iter]() {
                for (int i = 1; i < strs.size(); i++) {
                    if (strs[i][iter] != strs[i-1][iter]) return false;
                }
                return true;
            }()) {
                iter++;
            } else {
                break;
            }
        }
        return strs[0].substr(0, iter);
    }
};