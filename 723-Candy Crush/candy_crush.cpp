class Solution {
public:
    bool detect(vector<vector<int>> &board) {
        bool isStable = true;
        for(int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[0].size(); j ++) {
                //check row
                if(j <= board[0].size() - 3 && board[i][j] != 0) {
                    if(abs(board[i][j]) == abs(board[i][j+1]) && abs(board[i][j]) == abs(board[i][j+2])) {
                        // >= 3 same in row
                        isStable = false;
                        int ptr = j;
                        while(ptr + 1 < board[0].size() && abs(board[i][ptr]) == abs(board[i][ptr+1])) {
                            board[i][ptr] = -abs(board[i][ptr]);
                            ptr++;
                        }
                        board[i][ptr] = -abs(board[i][ptr]);
                    }
                }
                //check column
                if(i <= board.size() - 3 && board[i][j] != 0) {
                    int target = abs(board[i][j]);
                    if(abs(board[i+1][j]) == target && abs(board[i+2][j]) == target) {
                        // >=3 same in column
                        isStable = false;
                        int ptr = i;
                        while(ptr + 1 < board.size() && abs(board[ptr][j]) == abs(board[ptr+1][j])) {
                            board[ptr][j] = -abs(board[ptr][j]);
                            ptr++;
                        }
                        board[ptr][j] = -abs(board[ptr][j]);
                    }
                }
            }
        }
        return isStable;
    }
    
    void erase(vector<vector<int>> &board) {
        for(int j = 0; j < board[0].size(); j ++) {
            int ptr = board.size() - 1;
            for(int i = board.size() - 1; i >= 0; i --) {
                if(board[i][j] > 0) {
                    board[ptr--][j] = board[i][j];
                }
            }
            while(ptr >= 0) {
                board[ptr--][j] = 0;
            }
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(!detect(board)) {
            erase(board);
        }
        // for(auto vec : board) {
        //     for(auto e : vec) cout<<e <<"\t";
        //     cout<<endl;
        // }
        return board;
    }
};
