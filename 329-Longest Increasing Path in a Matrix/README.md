# Problem
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
```
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
```
Return 4

The longest increasing path is [1, 2, 6, 9].

Example 2:
```
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
```
Return 4

The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

## Idea
This problem has the property that can be solved using dfs. Since we want a path that is monotonically increasing, therefore, 
when we search that path, once we go from element A to element B, we know that A must be less than B, and when we search the
next element of B, there is no possibility that we may choose A again because we would only choose an element that is greater
than B, and A is not that element. This property leads to a great convenience:
```
we don't need to mark what elements have been selected in case we would choose an element twice
```
Hence, in this problem, we don't need to modify the original matrix, we just search forward.

Another property is also crucial. Suppose we know the path, and we look back on this path and would find the following:
If we know the length of path starting from one element, this would help us solve this problem with ease. Hence, this leads to 
the idea of dfs:

every time we find an element that can be concatenated to the path, we first compute the longest path starting from that element.
What's more, we store this answer in a matrix as well. By doing so, we can utilize the info and expidite the computation.
