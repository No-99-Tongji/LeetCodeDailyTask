#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int result = 0;
        int flag = -1;
        for (const char c : directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    result += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    result += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
            }
        }
        return result;
    }
};