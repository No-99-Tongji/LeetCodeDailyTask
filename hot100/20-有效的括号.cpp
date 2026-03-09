class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (const char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                if (c == ')') {
                    if (stk.top() != '(') return false;
                    else stk.pop();
                } else if (c == '}') {
                    if (stk.top() != '{') return false;
                    else stk.pop();                    
                } else if (c == ']') {
                    if (stk.top() != '[') return false;
                    else stk.pop();                    
                }
            }
        }
        return stk.empty();
    }
};