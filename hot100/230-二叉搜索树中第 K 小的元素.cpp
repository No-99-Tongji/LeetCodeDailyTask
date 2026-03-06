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
    vector<int> dfs(TreeNode* p) {
        vector<int> l, r;
        if (p->left) l = dfs(p->left);
        if (p->right) r = dfs(p->right);
        l.emplace_back(p->val);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v = dfs(root);
        return v[k-1];
    }
};