#include <iostream>
using namespace std;

class Solution {
public:
    bool check(const string& str) {
        int cnt = 0;
        for (const char c : str) {
            if (c == 'S') cnt++;
        }
        return (cnt & 1) == 0 && cnt != 0;
    }

    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        if (!check(corridor)) return 0;
        long long  result = 1;
        int p_cnt = 0;
        int s_cnt = 0;
        for (const char c : corridor) {
            if (c == 'S') s_cnt++;
            else if (s_cnt == 2) p_cnt++;
            if (s_cnt == 3) {
                s_cnt = 1;
                result = (result * (p_cnt + 1)) % mod;
                p_cnt = 0;
            }
        }
        return int(result);
    }
};