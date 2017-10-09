class Solution {
public:
    int minCut(string s) {
//         int n = s.length();
//         if(n<=1) return 0;
        
//         int mincuts[n+1];
//         for(int i = 0; i<n+1; i++) mincuts[i] = i-1;
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; i+j<n && i-j>=0 && s[i+j] == s[i-j]; j++){
//                 mincuts[i+j+1] = min(mincuts[i+j+1], mincuts[i-j]+1);
//             }
//             for(int j = 0; i+j<n && i-1-j>=0 && s[i+j] == s[i-1-j]; j++){
//                 mincuts[i+j+1] = min(mincuts[i+j+1], mincuts[i-1-j]+1);
//             }
//         }
//         return mincuts[n];
        
        int n = s.length();
        if(n<=1) return 0;
        bool isPalin[n][n] = {false};
        fill_n(&isPalin[0][0], n*n, false);
        int minCuts[n+1];
        for(int i = 0; i <= n; i++){
            minCuts[i] = i-1;
        }
         int i,j;
         for(j = 1; j < n; ++j)
         {
             for(i = j; i >= 0; --i)
            {
                if( (s[i] == s[j]) && ((j-i < 2) || isPalin[i+1][j-1]))
                {
                    isPalin[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], minCuts[i] + 1);
                }
            }
        }
        return minCuts[n];
    }
};
