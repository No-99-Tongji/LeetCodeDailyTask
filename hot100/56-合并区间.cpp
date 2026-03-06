#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (vector<int> a, vector<int>b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i-1][1]) {
                vector<int> new_vec = {intervals[i-1][0], max(intervals[i-1][1], intervals[i][1])};
                intervals.erase(intervals.begin() + i-1);
                intervals[i-1] = new_vec;
                // for (const int num : new_vec) {
                //     cout << num << ' ';
                // }
                // cout << endl;
                i--;
            }
        }
        return intervals;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    sol.merge(intervals);

    return 0;
}