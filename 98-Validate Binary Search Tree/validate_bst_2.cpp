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
    bool isValidBST(TreeNode* root) {
        TreeNode* curNode = root;
        stack<TreeNode*> stk;
        int prev;
        bool isEmpty = true;
        while(curNode != NULL || !stk.empty()) {
            while(curNode != NULL) {
                stk.push(curNode);
                curNode = curNode->left;
            }
            TreeNode* top = stk.top();
            stk.pop();
            if(isEmpty) {
                prev = top->val;
                isEmpty = false;
            }
            else {
                if(top->val <= prev) return false;
                else prev = top->val;
            }
            curNode = top->right;
        }
        return true;
    }
};
