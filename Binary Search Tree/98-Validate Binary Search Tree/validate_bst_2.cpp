class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> stk;
        TreeNode* cur_min = NULL;
        while(root != NULL || !stk.empty()){
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(cur_min != NULL && cur_min->val >= root->val) return false;
            cur_min = root;
            root = root->right;
        }
        return true;
    }
};
