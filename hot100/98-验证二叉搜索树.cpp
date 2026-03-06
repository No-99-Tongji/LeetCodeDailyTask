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
    bool dfs(TreeNode* p, long long& max_num, long long& min_num) {
        long long left_min = 4e9;
        long long left_max = -4e9;
        long long right_min = 4e9;
        long long right_max = -4e9;

        if (p->left) if (!dfs(p->left, left_max, left_min)) return false;
        if (p->right) if (!dfs(p->right, right_max, right_min)) return false;
        if (!(left_max < p->val && p->val < right_min)) return false;
        max_num = max({max_num, p->val, left_max, right_max});
        min_num = min({min_num, p->val, left_min, right_min});
        // cout << p->val << ": " << endl;
        // cout << "left_min: " << left_min << " left_max: " << left_max <<
        // " right_min: " << right_min << " right_max: " << right_max << endl;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        long long max_num = -4e9;
        long long min_num = 4e9;
        return dfs(root, max_num, min_num);
    }
};