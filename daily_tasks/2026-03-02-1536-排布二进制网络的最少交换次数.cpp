#include <iostream>
using namespace std;
#include <queue>
#include <unordered_map>

class Solution {
public:
    int ans = 0;
    unordered_map<vector<int>, int> mp;
    int r_zero_num(vector<int>& line) {
        int res = 0;
        int size = line.size();
        for (int i = size - 1; i > 0; i++) {
            if (line[i] == 0) res++;
            else break;
        }
        return res;
    }

    void swap(vector<int>& line1, vector<int>& line2) {
        ans++;
        auto temp = line1;
        line1 = line2;
        line2 = temp;
    }

    int minSwaps(vector<vector<int>>& grid) {
        for (auto& line : grid) {
            int num = r_zero_num(line);
            mp[line] = num;
        }
        for (int i = 0; i < grid.size(); i++) {
            if 
        }
    }
};