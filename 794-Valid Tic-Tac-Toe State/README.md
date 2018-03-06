# Problem
A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
```
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
```
Note:

* board is a length-3 array of strings, where each string board[i] has length 3.
* Each board[i][j] is a character in the set {" ", "X", "O"}.

## Idea
* 尽量只遍历一遍board来做
* 需要记录些什么来判断board是否合法呢？
* 首先就是棋子的个数，x与o的个数仅能是相等或者是大1的关系
* 其次就是棋子连成线的条数
* 当x与o同样多的个数时，我们知道此时如果游戏没结束，那么应当线的条数均为0，如果游戏结束了，应当是o赢了，换言之，x的线数必须为0.综合一下两种情况，可以得到条件是x的线数为0；
* 当x比o多1的时候，我们知道此时如果游戏没结束，那么应当线的条数均为0，如果游戏结束了，应当是x赢了，换言之，o的线数必须为0.同上


* 我们存下每行、每列的‘X'，'O'的出现次数，如果达到3，则说明连成了一条线
* 最后补一下两条对角线的情况即可
