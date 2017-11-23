class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size()-2; i >=0; i --){
            if(nums[i] < nums[i+1]) break;
        }
        if(i == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        else{
            //i points to the place that needs to be replaced by a slightly larger number
            int target = INT_MAX;
            int index = 0;
            for(int j = i+1; j < nums.size(); j ++){
                if(nums[j] > nums[i] && nums[j] - nums[i] < target){
                    index = j; 
                    target = nums[j] - nums[i];
                } 
            }
            //swap
            swap(nums[i], nums[index]);
            //sort the rest
            sort(nums.begin()+i+1, nums.end());
            return;
        }
    }
};
