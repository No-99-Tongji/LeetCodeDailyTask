#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> trans;
    string anagram(string str) {
        sort(str.begin(), str.end(), [] (char a, char b) {
            return a < b;
        });
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        for (const string& str : strs) {
            trans[anagram(str)].push_back(str);
        }
        for (const auto& p : trans) {
            vector<string> tmp;
            for (const string& str: p.second) {
                tmp.push_back(str);
            }
            res.push_back(tmp);
        }
        return res;
    }
};