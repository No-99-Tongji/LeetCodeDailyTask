#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    bool check(vector<int>& citations, int num) {
        int sum = 0;
        for (const int c : citations) {
            if (c >= num) sum++;
        }
        return sum >= num;
    }

    int hIndex(vector<int>& citations) {
        int m = *max_element(citations.begin(), citations.end());
        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(citations, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};