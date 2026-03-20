#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string trans(vector<string>& temp, int maxWidth) {
        int space_num = temp.size() - 1;
        int word_len_sum = [&temp] () {
            int ret = 0;
            for (const auto& str : temp) ret += str.size();
            return ret;
        }();
        int lower_bound_space_len = (maxWidth - word_len_sum) / space_num;
        int rest_space_len = (maxWidth - word_len_sum) - lower_bound_space_len;
        vector<string> spaces(space_num, string(lower_bound_space_len, ' '));
        for (int i = 0; i < rest_space_len; i++) spaces[i] += " ";
        string ret = "";
        [&ret, space_num, &temp, &spaces] () {
            for (int i = 0; i < space_num; i++) {
                ret += temp[i] + spaces[i];
            }
            ret += spaces[space_num];
        }();
        return ret;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;

        int idx = 0;
        while (true) {
            vector<string> temp;
            int len_sum = 0;
            int min_space_num = 0;
            while (len_sum + words[idx].size() + min_space_num <= maxWidth) {
                min_space_num++;
                len_sum += words[idx].size();
                temp.push_back(words[idx++]);
            }
            ret.push_back(trans(temp, maxWidth));
        }
        
    }
};