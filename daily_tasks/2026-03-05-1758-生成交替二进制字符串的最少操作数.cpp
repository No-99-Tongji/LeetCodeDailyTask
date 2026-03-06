class Solution {
public:
    void trans(char& c) {
        if (c == '0') c = '1';
        else c = '0';
    }

    int startWith(const string& s, bool isZero) {
        int result = 0;
        if (isZero) {
            char cur = '0';
            for (const char c : s) {
                if (c == cur) {
                    result++;
                }
                trans(cur);
            }
        } else {
            char cur = '1';
            for (const char c : s) {
                if (c == cur) {
                    result++;
                }
                trans(cur);
            }
        }
        return result;
    }

    int minOperations(string s) {
        return min(startWith(s, true), startWith(s, false));
    }
};

int main() {
    Solution sol;
    sol.minOperations("0100");

    return 0;
}