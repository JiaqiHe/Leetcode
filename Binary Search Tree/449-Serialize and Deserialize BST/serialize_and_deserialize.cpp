/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str_root;
        if(root == NULL) return str_root;
        str_root += to_string(root->val)+" ";
        string str_left = serialize(root->left);
        string str_right = serialize(root->right);
        return str_root+str_left+str_right;
    }
    
    vector<int> construct(string str){
        vector<int> nums;
        for(int i = 0; i < str.length(); i++){
            int cur_num = 0;
            while(str[i] != ' '){
                cur_num = cur_num*10 + str[i]-'0';
                i++;
            }
            nums.push_back(cur_num);
        }
        return nums;
    }
    
    TreeNode* buildTree(vector<int> nums, int begin, int end){
        if(begin>end) return NULL;
        TreeNode* root = new TreeNode(nums[begin]);
        int i = begin+1;
        while(i <= end && nums[i] < nums[begin]) i++;
        root->left = buildTree(nums, begin+1, i-1);
        root->right = buildTree(nums, i, end);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums = construct(data);
        return buildTree(nums, 0, nums.size()-1);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
