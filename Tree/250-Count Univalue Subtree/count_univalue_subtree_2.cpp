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
    bool compare(TreeNode* root){
        bool temp1=true, temp2=true,temp3=true, temp4=true;
        if(root == NULL) return true;
        if(root->left){
            temp1 = root->val == root->left->val;
            temp2 = compare(root->left);
        }
        if(root->right){
            temp3 = root->val == root->right->val;
            temp4 = compare(root->right);
        }
        if(temp1&&temp2&&temp3&&temp4) res++;
        return temp1&&temp2&&temp3&&temp4;
    }
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        compare(root);
        return res;
    }
};
