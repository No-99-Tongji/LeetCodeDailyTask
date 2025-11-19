#include <iostream>
using namespace std;

class Solution {
public:
    int highbit(int x) {
        return 1u<<(31-__builtin_clz(x));
    }

    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int high = highbit(n);
        if (high == n) return 2 * minimumOneBitOperations(n >> 1) + 1;
        return minimumOneBitOperations(high) - minimumOneBitOperations(n - high);
    }
};

int main() {
    Solution sol;
    cout << sol.minimumOneBitOperations(9) << endl;
    return 0;
}