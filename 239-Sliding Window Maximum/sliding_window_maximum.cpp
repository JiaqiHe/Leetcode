class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> decrease;
        for(int i = 0; i < nums.size(); i ++){
            if(!decrease.empty() && decrease.front() == i-k) decrease.pop_front();
            while(!decrease.empty() && nums[decrease.back()] <= nums[i]) decrease.pop_back();
            decrease.push_back(i);
            if(i>=k-1) res.push_back(nums[decrease.front()]);
        }
        return res;
    }
};
