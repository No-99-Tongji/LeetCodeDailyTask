#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<int, string> mp = {
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"}
    };
    vector<int> digits;
    vector<int> pos_num = {1, 10, 100, 1000};
    string process(int digit, int pos) {
        string ret = "";
        if (digit == 9) ret += (mp[pos_num[pos]] + mp[pos_num[pos+1]]);
        else if (digit == 4) ret += (mp[pos_num[pos]] + mp[5*pos_num[pos]]);
        else if (digit == 5) ret += mp[5*pos_num[pos]];
        else if (digit > 5 && digit < 9) ret += (mp[5*pos_num[pos]] + process(digit - 5, pos));
        else if (digit > 0) ret = mp[pos_num[pos]] + process(digit - 1, pos);
        return ret;
    }
    string intToRoman(int num) {
        string ret = "";
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            int digit = digits[i];
            ret += process(digit, i);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    string str = sol.intToRoman(3749);

    return 0;
}