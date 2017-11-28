# Problem
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

## Idea
Sudoku problem needs tricks to manipulate the index problems. First, we find secrets about the indices.

First, we denote block numbers as the following:

| 0 | 1 | 2 |
|---|---|---|
| 3 | 4 | 5 |
| 6 | 7 | 8 |

* case 1: we know element's row `i` and column `j`, how to find its block number?

The answer is `i/3*3 + j/3`.

* case 2: we know the block number `k`, how to find all 9 elements that are in this block?

Let `i` denote the i-th element in this block (i is from 0 to 8), then this element's coordinates in the big original matrix is:

row: `k/3*3 + i/3`

column: `k%3*3 + i%3`

Second, we can solve this problem. The idea is that we create three boolean vectors to monitor the occurance of 9 numbers in each row, column,
and block. We use backtracking to try each position that has a '.' with all 9 possible numbers while checking the compatibility with each
row, column and block. If we complete the last element, we then save this answer and return it.
