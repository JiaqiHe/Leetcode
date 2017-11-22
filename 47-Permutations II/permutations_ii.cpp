class Solution {
public:
    void traverse(vector<int> &nums, vector<vector<int>> &res, int i){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        } 
        unordered_set<int> dict;
        for(int j = i; j < nums.size(); j ++){
            if(dict.find(nums[j]) != dict.end()) continue;
            swap(nums[i], nums[j]);
            traverse(nums, res, i+1);
            swap(nums[i], nums[j]);
            dict.insert(nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        traverse(nums, res, 0);
        return res;
    }
};
