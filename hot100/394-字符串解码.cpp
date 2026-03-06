#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string s;
    int it;
    int parseNum() {
        int ret = 1;
        for (const char c : s.substr(it)) {
            if (isdigit(c)) {
                ret = ret * 10 + c - '0';
            } else break;
        }
        return ret;
    }

    string parseString() {
        if (it == s.size() || s[it] == ']') {
            return "";
        }

        char cur = s[it];
        int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            repTime += parseNum();
            it++;
            
        }
    }

    string decodeString(string s) {
        
    }
};