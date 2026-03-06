#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int> {};
        vector<int> result;
        vector<int> l_v;
        vector<int> r_v;
        if (root->left)
            l_v = inorderTraversal(root->left);
        if (root->right)
            r_v = inorderTraversal(root->right);
        for (const auto i : l_v) result.push_back(i);
        result.push_back(root->val);
        for (const auto i : r_v) result.push_back(i);
        return result;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
    }
};