class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int res = 0;
        int len = prices.size();
        int maximum_times = min(len, k);
        vector <int> dp0(maximum_times+1, 0);
        vector <int> dp1(maximum_times+1, -prices[0]);
        for(int i = 1; i < len; i ++){
            for(int t = 1; t <= maximum_times; t ++){
                int temp1 = dp1[t];
                int temp2 = dp0[t];
                int temp3 = dp0[t-1];
                dp0[t] = max(temp1+prices[i], temp2);
                dp1[t] = max(temp1, temp3-prices[i]);
                res = max(res, dp0[t]);
            }
        }
        
        // for(int i = 1; i < len; i ++){
        //     for(int t = 1; t <= maximum_times; t ++){
        //         dp0[i][t] = max(dp1[i-1][t]+prices[i], dp0[i-1][t]);
        //         dp1[i][t] = max(dp1[i-1][t], dp0[i-1][t-1]-prices[i]);
        //         res = max(res, dp0[i][t]);
        //     }
        // }
        return res;
    }
};
