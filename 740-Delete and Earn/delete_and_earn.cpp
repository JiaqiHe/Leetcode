class Solution {
public:
    /* 思路如下：
    * bucket sort一下，得到不同的数字以及出现次数
    * 接着，制作这样一个map，number->points，表示的含义是：从number开始选能得到的points
    * points初始化为number * 出现次数
    * 从最大的数往前走，逐个更新points，原则是：查比当前数字大1的那些数，从中挑一个points最大的，加到points上
    * 最后这些points中的最大值即为答案
    */
    // int deleteAndEarn(vector<int>& nums) {
    //     if(nums.empty()) return 0;
    //     map<int, int> dict;
    //     for(auto n : nums) dict[n]++;
    //     vector<pair<int, int>> numbers;
    //     for(auto p : dict) {
    //         numbers.push_back(make_pair(p.first, p.second * p.first));
    //     }
    //     int res = 0;
    //     for(int i = numbers.size() - 1; i >= 0; i --) {
    //         int toAdd = 0;
    //         for(int j = i + 1; j < numbers.size(); j ++) {
    //             if(numbers[j].first > numbers[i].first + 1 && numbers[j].second > toAdd) {
    //                 toAdd = numbers[j].second;
    //             }
    //         }
    //         numbers[i].second += toAdd;
    //         res = max(res, numbers[i].second);
    //     }
    //     return res;
    // }
    /* 思路如下：
    * bucket sort一下，得到不同的数字以及出现次数
    * 创建take和skip，含义是：从到index为i的数中选，且take该数和skip该数的最大points
    * 最后的答案是take和skip的最大值
    */
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int, int> dict;
        for(auto n : nums) dict[n]++;
        int take = 0, skip = 0;
        int last = INT_MIN;
        for(auto iter = dict.begin(); iter != dict.end(); iter++) {
            int takei, skipi;
            if(iter->first > last + 1) {
                takei = max(take, skip) + iter->first * iter->second;
                skipi = max(take, skip);
            } else {
                takei = skip + iter->first * iter->second;
                skipi = max(take, skip);
            }
            take = takei;
            skip = skipi;
            last = iter->first;
        }
        return max(take, skip);
    }
};
