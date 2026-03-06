#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int> continous_hbars(hBars.size(), 1), continous_vbars(vBars.size(), 1);

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int h_size = hBars.size(), v_size = vBars.size(), h_max = 1, v_max = 1;
        for (int i = 1; i < h_size; i++) {
            if (hBars[i-1] == hBars[i] - 1) {
                continous_hbars[i] = continous_hbars[i-1] + 1;
                h_max = max(h_max, continous_hbars[i]);
            }
        }
        for (int i = 1; i < v_size; i++) {
            if (vBars[i-1] == vBars[i] - 1) {
                continous_vbars[i] = continous_vbars[i-1] + 1;
                v_max = max(v_max, continous_vbars[i]);
            }
        }
        // cout << "h_max: " << h_max << ' ' << "v_max: " << v_max << endl;
        int min_len = min(h_max, v_max) + 1;
        return min_len * min_len;
    }
};

int main() {
    Solution sol;
    int n = 2, m = 1;
    vector<int> hBars = {2, 3}, vBars = {2};
    sol.maximizeSquareHoleArea(n, m, hBars, vBars);

    return 0;
}