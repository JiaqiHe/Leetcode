class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int count = 0;
                for(auto p : dirs) {
                    int r = i + p.first;
                    int c = j + p.second;
                    if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] > 0) count++;
                }
                if(board[i][j] == 0) board[i][j] = count == 3 ? -1 : -2;
                else board[i][j] = count > 3 || count < 2 ? 2 : 1;
            }
        }
        
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                board[i][j] = abs(board[i][j]) == 2 ? 0 : 1;
            }
        }
    }
};
