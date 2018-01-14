class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &len, int i, int j) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return 0;
        if(len[i][j] > 0) return len[i][j];
        if((i - 1 < 0 || matrix[i][j] <= matrix[i - 1][j]) 
           && (i + 1 >= matrix.size() || matrix[i][j] <= matrix[i + 1][j])
            && (j - 1 < 0 || matrix[i][j] <= matrix[i][j - 1]) 
           && (j + 1 >= matrix[0].size() || matrix[i][j] <= matrix[i][j + 1])) {
            len[i][j] = 1;
            return 1;
        }
        else {
            int cur = 0;
            if(i - 1 >= 0 && matrix[i][j] > matrix[i-1][j]) cur = max(cur, dfs(matrix, len, i - 1, j) + 1);
            if(i + 1 < matrix.size() && matrix[i][j] > matrix[i+1][j]) cur = max(cur, dfs(matrix, len, i + 1, j) + 1);
            if(j - 1 >= 0 && matrix[i][j] > matrix[i][j-1]) cur = max(cur, dfs(matrix, len, i, j - 1) + 1);
            if(j + 1 < matrix[0].size() && matrix[i][j] > matrix[i][j+1]) cur = max(cur, dfs(matrix, len, i, j + 1) + 1);
            len[i][j] = cur;
            return len[i][j];
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if(matrix.empty() || matrix[0].empty()) return res;
        vector<vector<int>> len(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i ++) {
            for(int j = 0; j < matrix[0].size(); j ++) {
                res = max(res, dfs(matrix, len, i, j));
            }
        }
        return res;
    }
};
