#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(int target, int l, int r, vector<int>& arr) {
        if (l == r) {
            if (target == arr[l]) return l;
            else return -1;
        }
        int mid = (l + r) / 2;
        if (arr[mid] < arr[l]) { // 非左起有序的
            int a = find(target, l, mid, arr);
            int b = find(target, mid+1, r, arr);
            if (a != -1) return a;
            else return b;
        } else { // 左起有序的
            if (arr[l] <= target && target <= arr[mid]) return find(target, l, mid, arr);
            return find(target, mid+1, r, arr);
        }
    }
    int search(vector<int>& nums, int target) {
        return find(target, 0, nums.size() - 1, nums);
    }
};