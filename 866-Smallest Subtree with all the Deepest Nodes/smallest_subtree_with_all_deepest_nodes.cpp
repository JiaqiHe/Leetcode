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
    TreeNode* LCA(TreeNode* leftMost, TreeNode* rightMost, TreeNode* root) {
        if(root == NULL || root == leftMost || root == rightMost) return root;
        TreeNode* left = LCA(leftMost, rightMost, root->left);
        TreeNode* right = LCA(leftMost, rightMost, root->right);
        return left == NULL ? (right == NULL ? NULL : right) : (right == NULL ? left : root);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // Step 1: find all deepest nodes
        // Step 2: find LCA of the left-most and right-most node
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        TreeNode* leftMost, *rightMost;
        while(!dq.empty()) {
            int len = dq.size();
            leftMost = dq.front();
            rightMost = dq.back();
            while(len-- > 0) {
                TreeNode* curNode = dq.front();
                dq.pop_front();
                if(curNode->left) dq.push_back(curNode->left);
                if(curNode->right) dq.push_back(curNode->right);
            }
        }
        
        return LCA(leftMost, rightMost, root);
    }
};
