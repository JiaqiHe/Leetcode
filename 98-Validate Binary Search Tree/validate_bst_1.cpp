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
    struct pack {
        int min;
        int max;
        bool isBST;
        bool isEmpty;
        pack(int min, int max, bool isBST, bool isEmpty) : min(min), max(max), isBST(isBST), isEmpty(isEmpty) {}
    };
    
    pack isBST(TreeNode* root) {
        if(root == NULL) return pack(INT_MAX,INT_MIN,true, true);
        if(root->left == NULL && root->right == NULL) return pack(root->val, root->val, true, false);
        pack left = isBST(root->left);
        pack right = isBST(root->right);
        if(!left.isBST || !right.isBST) return pack(0,0,false,false);
        //left and right are both BST
        if((left.isEmpty || (root->val > left.max)) && (right.isEmpty || (root->val < right.min))) return pack(min(root->val, left.min), max(root->val, right.max), true, false);
        else return pack(0,0,false, false);
    }
    
    bool isValidBST(TreeNode* root) {
        pack res = isBST(root);
        return res.isBST;
    }
};
