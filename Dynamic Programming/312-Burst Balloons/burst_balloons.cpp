class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        //add two 1s at two ends of the array
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[nums.size()][nums.size()] = {0};
        for(int length = 1; length <= len; length++){
            //length: the length of a subarray that we want to calculate
            for(int left = 1; left <= len-length+1; left ++){
                //left: the index of the first element of the subarray 
                int right = left + length - 1;
                for(int target = left; target <= right; target ++){
                    //target: the balloon that we want to burst
                    dp[left][right] = max(dp[left][right], 
                                         nums[target]*nums[left-1]*nums[right+1] + dp[left][target-1] + dp[target+1][right]);
                }
            }
        }
        return dp[1][len];
    }
};
