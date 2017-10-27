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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_begin, int pre_end, int in_begin, int in_end){
        if(pre_begin > pre_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        int temp;
        for(int i = in_begin; i <= in_end; i ++){
            if(inorder[i] == root->val){
                temp = i-in_begin;
                break;
            } 
        }
        root->left = build(preorder, inorder, pre_begin+1, pre_begin+temp, in_begin, in_begin+temp-1);
        root->right = build(preorder, inorder, pre_begin+temp+1, pre_end, in_begin+temp+1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return build(preorder, inorder, 0, len-1, 0, len-1);
    }
};
