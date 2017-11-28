class Solution {
public:
    bool solve(vector<vector<char>> &board, vector<vector<bool>> &row_visited, vector<vector<bool>> &col_visited, vector<vector<bool>> &block_visited, int num){
        if(num == 81){
            return true;
        } 
        int x = num/9;
        int y = num%9;
        if(board[x][y] != '.') return solve(board, row_visited, col_visited, block_visited, num+1);
        else {
            for(int i = 0; i < 9; i ++){
                if(row_visited[x][i] == true || col_visited[y][i] == true || block_visited[x/3*3+y/3][i] == true) continue;
                else{
                    board[x][y] = i + '1';
                    row_visited[x][i] = true;
                    col_visited[y][i] = true;
                    block_visited[x/3*3+y/3][i] = true;
                    if(solve(board, row_visited, col_visited, block_visited, num+1)) return true;
                    board[x][y] = '.';
                    row_visited[x][i] = false;
                    col_visited[y][i] = false;
                    block_visited[x/3*3+y/3][i] = false;
                }
            }
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_visited(9, vector<bool>(9, false));
        vector<vector<bool>> col_visited(9, vector<bool>(9, false));
        vector<vector<bool>> block_visited(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                //update row_visited
                if(board[i][j] != '.') row_visited[i][board[i][j] - '1'] = true;
                //update col_visited
                if(board[j][i] != '.') col_visited[i][board[j][i] - '1'] = true;
            }
            //update block_visited
            for(int k = 0; k < 9; k ++){
                int x = i/3*3 + k/3;
                int y = i%3*3 + k%3;
                if(board[x][y] != '.') block_visited[i][board[x][y] - '1'] = true;
            }
        }
        solve(board, row_visited, col_visited, block_visited, 0);
        return;
    }
};
