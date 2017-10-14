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
    vector<int> res;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        dfs(root);
        for(int i = 1; i< res.size(); i++){
            if(res[i]>res[i-1]) continue;
            else return false;
        }
        return true;
    }
};
