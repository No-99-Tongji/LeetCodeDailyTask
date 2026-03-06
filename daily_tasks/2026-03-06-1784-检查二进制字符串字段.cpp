#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s == "") return true;
        char pre = s[0];
        int change_num = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != pre) change_num++;
            pre = s[i];
        }
        if (s[0] == '0') change_num--;
        if (change_num > 1) return false;
        else return true;
    }
};