#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pows;
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        pows.push_back(1);
        for (int i = 1; i < 30; i++) pows.push_back(2 * pows[i-1]);
        return ~n + *upper_bound(pows.begin(), pows.end(), n);
    }
};