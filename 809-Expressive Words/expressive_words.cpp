class Solution {
public:
    struct result {
        vector<int> nums;
        string pattern;
        result(vector<int> nums, string pattern) : nums(nums), pattern(pattern) {}
    };
    
    result transform(string S) {
        string pattern = "";
        vector<int> nums;
        int ptr = 0;
        char c = S[ptr];
        int last = ptr;
        while(ptr < S.length()) {
            while(ptr < S.length() && c == S[ptr]) ptr++;
            nums.push_back(ptr - last);
            pattern += c;
            if(ptr < S.length()) c = S[ptr];
            last = ptr;
        }
        return result(nums, pattern);
    }
    
    int expressiveWords(string S, vector<string>& words) {
        result res_S = transform(S);
        int ans = words.size();
        for(string word : words) {
            result cur_res = transform(word);
            if(cur_res.pattern == res_S.pattern) {
                for(int i = 0; i < cur_res.nums.size(); i ++) {
                    if(!((cur_res.nums[i] == 1 && res_S.nums[i] != 2) || 
                         (cur_res.nums[i] > 1 && res_S.nums[i] >= cur_res.nums[i]))) {
                         ans -= 1;
                         break;
                    }
                }
            }
            else {
                ans -= 1;
            }
        }
        return ans;
    }
};
