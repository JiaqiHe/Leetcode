class Solution {
public:
    void dfs(int dict[], int &res, int cur_res, int i){
        cur_res += dict[i];
        if(i>7 || (dict[2*i] == -1 && dict[2*i+1] == -1)){
            res += cur_res;
            cout<<res<<endl;
            return;
        }
        if(dict[2*i] != -1) dfs(dict, res, cur_res, 2*i);
        if(dict[2*i+1] != -1) dfs(dict, res, cur_res, 2*i+1);
        return;
    }
    int pathSum(vector<int>& nums) {
        int res = 0;
        if(nums.empty()) return res;
        int dict[16] = {-1};
        for(int i = 0; i < 16; i ++){
            dict[i] = -1;
        }
        for(int i = 0; i < nums.size(); i ++){
            int hundreds = nums[i]/100;
            int tens = nums[i]/10%10;
            int units = nums[i]%10;
            dict[(int)pow(2, hundreds-1)+tens-1] = units;
        }
        int cur_res = 0;
        dfs(dict, res, cur_res, 1);
        return res;
    }
};
