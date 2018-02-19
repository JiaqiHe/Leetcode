class Solution {
public:
    //bs
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[right]) {
                //left part is in order
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1; //⚠️注意这里！如果写成left = mid可能会死循环。这里我们可以保证说，nums[mid] != target了，所以可以放心+1
                }
            } else if(nums[mid] < nums[right]) {
                //right part is in order
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } 
            else {
                right--;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
