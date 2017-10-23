class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        for(int i = 1; i < n; i ++){
            dp[i] = min(dp[ptr2]*2, min(dp[ptr3]*3, dp[ptr5]*5));
            if(dp[i] == dp[ptr2]*2) ptr2++;
            if(dp[i] == dp[ptr3]*3) ptr3++;
            if(dp[i] == dp[ptr5]*5) ptr5++;
        }
        return dp[n-1];
    }
};
