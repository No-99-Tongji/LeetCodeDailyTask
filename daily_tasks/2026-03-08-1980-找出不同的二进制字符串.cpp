#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> mp;
    int parseString(const string& s) {
        int ret = 0;
        for (char c : s) {
            ret = 2 * ret + c - '0';
        }
        return ret;
    }

    string toString(int num, int bit_num) {
        string ret = "";
        while (bit_num--) {
            char c = (num & 1) + '0';
            ret = string(1, c) + ret;
            num >>= 1;
        }
        return ret;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for (const string& s : nums) {
            mp[parseString(s)] = true;
        }
        for (int i = 0; i < (1 << n); i++) {
            if (mp.find(i) == mp.end()) {
                return toString(i, n);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    vector<string> nums = {"00","01"};
    sol.findDifferentBinaryString(nums);

    return 0;
}