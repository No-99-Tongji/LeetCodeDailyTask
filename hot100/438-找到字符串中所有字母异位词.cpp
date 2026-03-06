#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        
        vector<int> c_num(26, 0);
        vector<int> base_num(26, 0);
        
        for (const char c : p) {
            base_num[c - 'a']++;
        }
        
        for (int i = 0; i < p.size(); i++) {
            c_num[s[i] - 'a']++;
        }
        
        if (c_num == base_num) {
            result.push_back(0);
        }
        
        for (int i = 0; i + p.size() < s.size(); i++) {
            c_num[s[i] - 'a']--;
            c_num[s[i + p.size()] - 'a']++;
            
            if (c_num == base_num) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "ab";
    vector<int> result = sol.findAnagrams(s, p);
    
    cout << "Result: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}