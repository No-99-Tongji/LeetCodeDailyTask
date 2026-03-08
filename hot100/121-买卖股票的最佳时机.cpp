#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_num = prices[0];
        int ret = 0;
        for (const int p : prices) {
            ret = max(ret, p - min_num);
            min_num = min(min_num, p);
        }
        return ret;
    }
};