/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root != NULL) {
            TreeLinkNode* dummy = new TreeLinkNode(0);
            TreeLinkNode* iter = dummy;
            for(; root != NULL; root = root->next) {
                if(root->left != NULL) {
                    iter->next = root->left;
                    iter = iter->next;
                }
                if(root->right != NULL) {
                    iter->next = root->right;
                    iter = iter->next;
                }
            }
            root = dummy->next;
        }
    }
};
