#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<int, bool> hash_map;
    int findFinalValue(vector<int>& nums, int original) {
        for (const int num : nums) {
            hash_map[num] = true;
        }

        while (hash_map.find(original) != hash_map.end()) {
            original += original;
        }
        return original;
    }
};