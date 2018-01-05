class Solution {
public:
    //DP
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int res = 0;
        int len = s.length();
        vector<int> dp(len);
        for(int i = 1; i < len; i ++) { 
            if(s[i] == '(') {
                dp[i] = 0;
            } else {
                int pre_len = dp[i - 1];
                if(i - pre_len > 0 && s[i - pre_len - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if(i - pre_len - 1 > 0) dp[i] += dp[i - pre_len - 2];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
