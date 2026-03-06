#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int num = q.size();
            vector<int> line;
            while (num--) {
                auto u = q.front();
                q.pop();
                line.push_back(u->val);
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }
            result.push_back(line);
        }
        return result;
    }
};