# Problem
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```
Return 4.

## Idea
In this problem, we define the state to be the maximal size of the square that can be achieved at point (i, j), denoted as ```P[i][j]```.

In fact, ```P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1```
