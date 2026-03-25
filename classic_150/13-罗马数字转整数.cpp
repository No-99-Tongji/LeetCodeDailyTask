#include <string>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
    };

    int romanToInt(string s) {
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; ) {
            if (n - i >= 2) {
                if (mp.find(s.substr(i, 2)) != mp.end()) {
                    ret += mp[s.substr(i, 2)];
                    i+=2;
                } else {
                    ret += mp[s.substr(i, 1)];
                    i+=1;
                }
            } else {
                ret += mp[s.substr(i, 1)];
                i+=1;
            }
        }
        return ret;
    }
};