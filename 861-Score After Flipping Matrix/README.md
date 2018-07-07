## Problem
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:
```
Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
```
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].

0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

Note:

* 1 <= A.length <= 20
* 1 <= A[0].length <= 20
* A[i][j] is 0 or 1.

## Idea
Greedy，不用想的太复杂！

首先，对于行来说，因为一行代表一个数，怎么让它尽可能大呢？显然是无论如何，首位必须得是1，因此我们先把首位不是1的全部按行flip一下。如此之后，第一列就全是1了。

再者，考虑其他列。怎样让每列尽可能大呢？应当是让每列1的个数超过0的个数，因此我们把不满足该条件的列按列flip。

然后就完成了。不用怀疑就是这样！为什么呢？类似反证法：

此时，我们得到的矩阵满足下面两条非常重要的性质：
* 第一列全1
* 第二至最后一列，1的个数大于等于0的个数

我们肯定不能flip任何一行，因为要保证首位为1；我们也不能flip任何一列，否则就会使得和变小。总之，就是不能再flip了，所以此时是最大的状态了。
