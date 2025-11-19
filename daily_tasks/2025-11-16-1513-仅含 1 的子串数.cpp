#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sub_one_num;
    int mod = 1e9+7;

    void init() {
        int len = 1e5+1;
        sub_one_num.resize(len);
        int prefix = 0;
        sub_one_num[0] = 0;
        for (int i = 1; i < len; i++) {
            sub_one_num[i] = (sub_one_num[i-1] + i) % mod;
        }
        
    }

    int numSub(string s) {
        init();
        int sum = 0;
        int res = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                sum++;
            }
            else {
                res = (res + sub_one_num[sum]) % mod;
                sum = 0;
            }
        }
        res = (res + sub_one_num[sum]) % mod;
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.numSub("101") << endl;
}