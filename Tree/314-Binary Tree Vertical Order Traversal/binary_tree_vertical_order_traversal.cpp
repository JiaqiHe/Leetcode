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
    vector<vector<int>> res;
    unordered_map<int, vector<int>> dict;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return res;
        int mini = 0;
        int maxi = 0;
        queue<pair<TreeNode*, int>> que;
        pair<TreeNode*, int> p(root, 0);
        que.push(p);
        while(!que.empty()){
            pair<TreeNode*, int> cur_pair = que.front();
            que.pop();
            if(dict.find(cur_pair.second) != dict.end()){
                dict[cur_pair.second].push_back(cur_pair.first->val);
            }
            else{
                vector<int> temp(1, cur_pair.first->val);
                dict[cur_pair.second] = temp;
            }
            TreeNode* cur_node = cur_pair.first;
            int index = cur_pair.second;
            if(cur_node->left){
                mini = min(mini, index-1);
                pair<TreeNode*, int> p1(cur_node->left, index-1);
                que.push(p1);
            }
            if(cur_node->right){
                maxi = max(maxi, index+1);
                pair<TreeNode*, int> p2(cur_node->right, index+1);
                que.push(p2);
            }
        }
        for(int i = mini; i <= maxi; i ++){
            res.push_back(dict[i]);
        }
        return res;
    }
};
