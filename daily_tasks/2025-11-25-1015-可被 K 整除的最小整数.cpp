#include <iostream>
using namespace std;

class Solution {
public:
    const int n = 50;
    vector<int> rest;
    int smallestRepunitDivByK(int k) {
        rest.resize(n+1);
        rest[1] = 1;
        for (int i = 2; i <= n; i++) {
            rest[i] = (10 * rest[i-1]) % k;
            // cout << "rest[" << i << "]: " << rest[i] << endl;
        }
        int len = 0;
        int sum = 0;
        while (++len <= n) {
            sum += rest[len];
            // cout << "sum: " << sum << endl;
            if (sum % k == 0) return len;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    sol.smallestRepunitDivByK(2);

    return 0;
}