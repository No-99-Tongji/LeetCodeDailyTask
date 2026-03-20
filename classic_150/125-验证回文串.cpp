#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string trans(const string& str) {
        string ret = "";
        for (char c : str) {
            if (isalpha(c) || isdigit(c)) {
                if (c >= 'A' && c <= 'Z')
                    ret += string(1, c - ('A' - 'a'));
                else
                    ret += string(1, c);
            }
        }
        return ret;
    }
    bool isPalindrome(string s) {
        s = trans(s);
        int n = s.size();
        if (n == 0) return true;
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
};