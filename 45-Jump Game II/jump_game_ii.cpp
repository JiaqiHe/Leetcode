class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0;
        int cur_pos = 0;
        priority_queue<int> list;
        list.push(nums[0]);
        while(cur_pos < nums.size()-1){
            int max_leap = list.top();
            list = priority_queue <int>();
            for(int i = cur_pos+1; i < nums.size() && i <= cur_pos+max_leap; i ++){
                list.push(nums[i]-cur_pos-max_leap+i);
            }
            cur_pos += max_leap;
            res++;
        }
        return res;
    }
};
