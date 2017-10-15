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
    map<TreeNode*, bool> dict;
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return res;
        if(root->left) countUnivalSubtrees(root->left);
        if(root->right) countUnivalSubtrees(root->right);
        if((root->left == NULL ||(root->left && root->val == root->left->val) && dict[root->left]) &&
           (root->right == NULL ||(root->right && root->val == root->right->val) && dict[root -> right])){
            res++;
            dict[root] = true;
        }
        return res;
    }
};
