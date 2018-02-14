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
    struct BST {
        int maxval;
        int minval;
        int size;
        bool isBST;
        BST(int max, int min, int size, bool flag): maxval(max), minval(min), size(size), isBST(flag) {}
    };
    
    BST judge(TreeNode* root) {
        if(root == NULL) return BST(INT_MIN,INT_MAX,0,true);
        BST left = judge(root->left);
        BST right = judge(root->right);
        if(!left.isBST || !right.isBST) return BST(0,0,max(left.size, right.size), false);
        else {
            if(root->val > left.maxval && root->val < right.minval) {
                // is bst
                return BST(max(root->val, right.maxval), min(root->val, left.minval), left.size + right.size + 1, true);
            }
            else {
                return BST(0,0,max(left.size, right.size),false);
            }
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        BST ans = judge(root);
        return ans.size;
    }
};

//TIME COMPLEXITY: O(n)

//Space complexity: O(depth of the tree)
