class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int len_s = s.length(), len_p = p.length();
        bool dp[len_s+1][len_p+1];
        dp[0][0] = true;
        for(int i = 1; i <= len_p; i ++){
            //initialize dp[0][i]
            dp[0][i] = i>1 && p[i-1] == '*' && dp[0][i-2];
        }
        for(int i = 1; i <= len_s; i ++){
            dp[i][0] = false;
        }
        for(int i = 1; i <= len_s; i ++){
            for(int j = 1; j <= len_p; j ++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
                else{
                    dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.')&& dp[i-1][j]);
                }
            }
        }
        return dp[len_s][len_p];
    }
};
