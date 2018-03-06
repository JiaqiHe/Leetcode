class Solution {
public:
    /* 尽量只遍历一遍board来做
    * 需要记录些什么来判断board是否合法呢？
    * 首先就是棋子的个数，x与o的个数仅能是相等或者是大1的关系
    * 其次就是棋子连成线的条数
    * 当x与o同样多的个数时，我们知道此时如果游戏没结束，那么应当线的条数均为0，如果游戏结束了，应当是o赢了，换言之，x的线数必须为0.综合一下两种情况，可以得到条件是x的线数为0；
    * 当x比o多1的时候，我们知道此时如果游戏没结束，那么应当线的条数均为0，如果游戏结束了，应当是x赢了，换言之，o的线数必须为0.同上
    
    
    * 我们存下每行、每列的‘X'，'O'的出现次数，如果达到3，则说明连成了一条线
    * 最后补一下两条对角线的情况即可
    */
    bool validTicTacToe(vector<string>& board) {
        int numX = 0, numO = 0;
        int chainX = 0, chainO = 0;
        int row[3][2] = {0}, col[3][2] = {0};
        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 3; j ++) {
                if(board[i][j] == 'X') {
                    if(++row[i][0] == 3) chainX++;
                    if(++col[j][0] == 3) chainX++;
                    numX++;
                }
                else if(board[i][j] == 'O') {
                    if(++row[i][1] == 3) chainO++;
                    if(++col[j][1] == 3) chainO++;
                    numO++;
                }
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if(board[0][0] == 'O') chainO++;
            else if(board[0][0] == 'X') chainX++;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if(board[0][2] == 'O') chainO++;
            else if(board[0][2] == 'X') chainX++;
        }
        return (numX == numO && chainX == 0) ||
            (numX == numO + 1 && chainO == 0);
    }
};
