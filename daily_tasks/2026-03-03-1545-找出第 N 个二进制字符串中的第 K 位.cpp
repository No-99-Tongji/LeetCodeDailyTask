class Solution {
public:
    int power(int a, int b) {
        int res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
        }
        return res;
    }

    char invert(char c) {
        if (c == '0') return '1';
        else return '0';
    }

    char findKthBit(int n, int k) {
        if (n == 1 && k == 1) return '0';

        int size = power(2, n) - 1;
        if (k == size / 2 + 1) return '1';
        else if (k < size / 2 + 1) return findKthBit(n-1, k);
        else return invert(findKthBit(n-1, size - k + 1));
    }
};