class Solution {
public:
    void search(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >=board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return;
        board[i][j] = '*';
        search(board, i-1, j);
        search(board, i+1, j);
        search(board, i, j-1);
        search(board, i, j+1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        for(int j = 0; j < board[0].size(); j ++){
            search(board, 0, j);
            search(board, board.size()-1, j);
        } 
        for(int i = 1; i < board.size()-1; i ++){
            search(board, i, 0);
            search(board, i, board[0].size()-1);
        } 
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
        return;
    }
};
