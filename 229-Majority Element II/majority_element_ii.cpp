class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0, at=0, b=1, bt=0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==a) at++;
            else if(nums[i]==b) bt++;
            else if(at==0){
                a = nums[i];
                at = 1;
            }
            else if(bt==0){
                b = nums[i];
                bt = 1;
            }
            else{
                at--;
                bt--;
            }
        }
        at=0, bt=0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==a) at++;
            if(nums[i]==b) bt++;
        }
        vector<int> res;
        if(at>nums.size()/3) res.push_back(a);
        if(bt>nums.size()/3) res.push_back(b);
        return res;
    }
};
