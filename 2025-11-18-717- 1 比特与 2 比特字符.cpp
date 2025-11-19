#include <iostream>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        
        for (int i = 0; i < len; i++) {
            if (bits[i] == 0) {
                if (i == len - 1) return true;
            }
            else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> bits = {1, 1, 1, 0};

    cout << sol.isOneBitCharacter(bits) << endl;

    return 0;
}