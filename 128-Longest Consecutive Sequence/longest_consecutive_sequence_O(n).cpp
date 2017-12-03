class Solution {
public:
    int expand(int num, unordered_map<int, bool> &dict, int res){
        if(dict.find(num) == dict.end() || dict[num]) return res;
        dict[num] = true;
        res++;
        int right = expand(num + 1, dict, 0);
        int left = expand(num - 1, dict, 0);
        return res + left + right;
    }
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, bool> dict;
        for(auto num : nums){
            dict[num] = false;
        }
        for(auto num : nums){
            if(!dict[num]){
                res = max(res, expand(num, dict, 0));
            }
        }
        return res;
    }
};
