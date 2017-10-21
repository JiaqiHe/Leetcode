class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else{
                    if(matrix[i][j] == '1') dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                    else dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res*res;
    }
};
