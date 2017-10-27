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
     TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_begin, int in_end, int post_begin, int post_end){
        if(in_begin > in_end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int temp;
        for(int i = in_begin; i <= in_end; i ++){
            if(inorder[i] == root->val){
                temp = i-in_begin;
                break;
            } 
        }
        root->left = build(inorder, postorder, in_begin, in_begin+temp-1, post_begin, post_begin+temp-1);
        root->right = build(inorder, postorder, in_begin+temp+1, in_end, post_begin+temp, post_end-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return build(inorder, postorder, 0, len-1, 0, len-1);
    }
};
