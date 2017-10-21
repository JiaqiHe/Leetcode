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
    vector<TreeNode*> construct(int begin, int end){
        vector<TreeNode*> res;
        if(begin > end){
            res.push_back(NULL);
            return res;
        }
        for(int i = begin; i <= end; i++){
            vector<TreeNode*> left = construct(begin, i-1);
            vector<TreeNode*> right = construct(i+1, end);
            for(int l = 0; l < left.size(); l ++){
                for(int r = 0; r < right.size(); r ++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;
        return construct(1, n);
    }
};
