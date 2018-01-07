class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int len = nums.size();
        int ptr = 0;
        while(ptr < len) {
            if(nums[ptr] > len || nums[ptr] <= 0) ptr++;
            else {
                if(nums[ptr] != ptr + 1 && nums[ptr] != nums[nums[ptr] - 1]) swap(nums[ptr], nums[nums[ptr] - 1]);
                else ptr++;
            }
        }
        // for(auto elem : nums) cout<<elem<<" ";
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
