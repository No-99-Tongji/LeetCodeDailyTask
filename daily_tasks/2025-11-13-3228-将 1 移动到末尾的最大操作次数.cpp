#include <iostream>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int len = s.size();
        int mult_base = 0;
        int res = 0;
        int pos = len-2;
        if (s[len-1]=='0') mult_base++;
        while (pos >= 0) {
            if (s[pos] == '0') {
                if (s[pos+1] == '1')
                    mult_base++;
            }
            else {
                res += mult_base;
            }
            pos--;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.maxOperations("1001101") << endl;

    return 0;
}