class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> dp1(nums.size() - k + 1, 0);
        for(int i = 0; i + k <= nums.size(); i ++){
            if(i == 0){
                for(int j = 0; j < k; j ++){
                    dp1[i] += nums[i + j];
                }
            }
            else dp1[i] = dp1[i-1] - nums[i-1] + nums[i + k - 1];
        }
        
        vector<int> left(nums.size() - k + 1, 0);
        vector<int> right(nums.size() - k + 1, 0);
        for(int i = k; i <= nums.size()-k; i ++){
            left[i] = dp1[left[i-1]] >= dp1[i-k] ? left[i-1] : (i-k); 
        }
        
        for(int i = nums.size() - 2*k; i >= 0; i --){
            if(i == nums.size() - 2*k) right[i] = i+k;
            else right[i] = dp1[right[i+1]] > dp1[i+k] ? right[i+1] : (i+k);
        }
        
        int res = INT_MIN;
        vector<int> output;
        for(int i = k; i <= nums.size()-2*k; i ++){
            int cur = dp1[i] + dp1[left[i]] + dp1[right[i]];
            if(cur > res){
                res = cur;
                output = {left[i], i, right[i]};
            }
        }
        return output;
    }
};
