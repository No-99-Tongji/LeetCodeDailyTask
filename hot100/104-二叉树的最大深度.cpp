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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int l_h = 0;
        int r_h = 0;
        if (root->left) l_h = maxDepth(root->left);
        if (root->right) r_h = maxDepth(root->right);
        return max(l_h, r_h) + 1;
    }
};