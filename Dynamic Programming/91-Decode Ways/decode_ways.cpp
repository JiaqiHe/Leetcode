class Solution {
public:
    int numDecodings(string s) {
        if(s == "" || s[0] == '0') return 0;
        int len = s.length();
        int dp[len + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < len; i ++){
            dp[i+1] = 0;
            int tens = s[i-1] - '0';
            int num = tens * 10 + s[i] -'0';
            if(num >= 10 && num <= 26) dp[i+1] += dp[i-1];
            if(s[i] -'0' >=1 && s[i] - '0' <= 9) dp[i+1] += dp[i];
        }
        return dp[len];
    }
};
