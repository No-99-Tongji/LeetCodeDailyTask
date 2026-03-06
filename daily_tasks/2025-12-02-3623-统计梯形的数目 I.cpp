#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;
    unordered_map<int, long long> y_num;
    int countTrapezoids(vector<vector<int>>& points) {
        long long result = 0;
        long long sum = 0;
        for (const auto& p : points) {
            y_num[p[1]]++;
        }
        for (auto& [_, num] : y_num) {
            long long line_num = num * (num - 1) / 2;
            result = (result + sum * line_num) % mod;
            sum = (sum + line_num) % mod;
        }
        return result;
    }
};