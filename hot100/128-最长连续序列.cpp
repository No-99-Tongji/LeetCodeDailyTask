#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> pa, size;
    unordered_map<int, bool> hash_map;

    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }

    int longestConsecutive(vector<int>& nums) {
        for (const int num : nums) {
            hash_map[num] = true;
            pa[num] = num;
            size[num] = 1;
        }
        int res = 0;
        for (const int num : nums) {
            if (hash_map.find(num-1) != hash_map.end()) unite(num, num-1);
            if (hash_map.find(num+1) != hash_map.end()) unite(num, num+1);
        }
        for (const auto& p : size) {
            res = max(res, p.second);
        }
        // for (const int num: nums) {
        //     cout << "num: " << num << " pa: " << pa[num] << endl;
        // }
        // cout << endl;
        // map<int, bool> outed;
        // for (const int num: nums) {
        //     if (outed.find(find(num)) == outed.end()) {
        //         outed[find(num)] = true;
        //         cout << "pa: " << find(num) << " size: " << size[find(num)] << endl;
        //     }
        // }
        // cout << endl;

        return res;
    }
};

int main() {
    vector<int> input = {9,-1,4,-9,-3,0,-8,2,6,-4,-3,4,1,3,5,5,-7,-7,1,-9,-3,3,8,4,1,2};
    Solution sol;
    cout << sol.longestConsecutive(input) << endl;
}