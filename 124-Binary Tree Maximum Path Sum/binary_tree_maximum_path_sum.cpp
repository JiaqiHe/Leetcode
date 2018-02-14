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
    int findPath(TreeNode* root, int &res) {
        if(root == NULL) return 0;
        int left = findPath(root->left, res);
        int right = findPath(root->right, res);
        int m = max(left, right);
        int toReturn = m > 0 ? m + root->val : root->val;
        res = max(max(res, toReturn), left + right + root->val);
        return toReturn;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int res = INT_MIN;
        findPath(root, res);
        return res;
    }
};

//time complexity: O(n)
//space complexity: O(depth of tree)
