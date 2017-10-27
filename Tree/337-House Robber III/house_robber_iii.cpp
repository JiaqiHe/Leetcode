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
    int res = 0;
    int robhelper(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            res = max(res, root->val);
            return root->val;
        } 
        //don't rob root
        int con1 = robhelper(root->left) + robhelper(root->right);
        //rob root
        int con2_1 = 0;
        int con2_2 = 0;
        if(root->left) con2_1 = robhelper(root->left->left) + robhelper(root->left->right);
        if(root->right) con2_2 = robhelper(root->right->left) + robhelper(root->right->right);
        int con2 = con2_1 + con2_2 + root->val;
        res = max(res, max(con1, con2));
        return max(con1, con2);
    }
    int rob(TreeNode* root) {
        robhelper(root);
        return res;
    }
};
