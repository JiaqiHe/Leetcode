class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int begin = 0;
        while(begin != slow) {
            begin = nums[begin];
            slow = nums[slow];
        }
        return begin;
    }
};
