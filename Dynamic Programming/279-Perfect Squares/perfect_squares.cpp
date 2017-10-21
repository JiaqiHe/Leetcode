class Solution {
public:
    int numSquares(int n) {
        int res[n+1];
        res[0] = 0;
        for(int i = 1; i <= n; i ++){
            res[i] = i;
            int base = 1;
            while(i >= base*base){
                res[i] = min(res[i], res[i-base*base]+1);
                base++;
            }
        }
        return res[n];
    }
};
