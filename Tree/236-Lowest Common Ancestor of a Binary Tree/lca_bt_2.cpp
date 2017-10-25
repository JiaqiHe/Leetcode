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
    bool dfs(TreeNode* root, TreeNode* p){
        if(root == NULL) return false;
        if(root == p) return true;
        bool left = dfs(root->left, p);
        bool right = dfs(root->right, p);
        return left||right;
    }
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q) return root; 
        bool left = dfs(root->left, p);
        bool right = dfs(root->left, q);
        if(left && right){
            return find(root->left, p, q);
        }
        else if(!left && !right){
            return find(root->right, p, q);
        }
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};
