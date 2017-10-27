/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int &res){
        if(root == NULL) return 0;
        int l = helper(root->left, res);
        int r = helper(root->right, res);
        int max_single = max(max(l, r)+root->val, root->val);
        int max_double = max(max_single, l+r+root->val);
        res = max(res, max_double);
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};
