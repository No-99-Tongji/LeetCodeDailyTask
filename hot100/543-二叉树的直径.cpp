struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

class Solution {
public:
    int result = 0;

    int dfs(TreeNode* p) {
        int l = 0, r = 0;
        if (p->left) l = dfs(p->left);
        if (p->right) r = dfs(p->right);
        result = max(result, l + r + 1);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return result - 1;
    }
};