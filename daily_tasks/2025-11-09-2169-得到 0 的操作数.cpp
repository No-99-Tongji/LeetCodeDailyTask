#include<iostream>
using namespace std;

class Solution {
public:
    int cnt(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0) return 0;
        return cnt(a-b, b) + 1;
    }
    int countOperations(int num1, int num2) {
        return cnt(num1, num2);
    }
};

int main() {
    Solution sol;
    cout << sol.countOperations(79, 68) << endl;
    return 0;
}