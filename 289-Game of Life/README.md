# Problem
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

* Any live cell with fewer than two live neighbors dies, as if caused by under-population.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by over-population..
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

## Idea
The requirement of __in-place__ can be regarded as a hint.

The way we do in-place manipulation of a matrix is to set a bunch of distinct marks to represent different cases, and search
the matrix for at least two times to complete the goal.

In this problem, we need to update the status at the same time. Thus, we can set the following:
* __0__: dead at this round (given by the problem)
* __1__: live at this round (given by the problem)
* __-1__: dead at this round, live next round
* __-2__: dead at this round, dead next round
* __1__: live at this round, live next round
* __2__: live at this round, dead next round

As we can see, if we use marks above, we maintain the status of both this round and next round. Using both positive and negative 
numbers can also bring convenience:

__Positive numbers__ represent that the cell is live at this round;

__Non-positive numbers__ represent that the cell is dead at this round;

__absolute value being 1__ represent that the cell would live next round;

__absolute value being 2__ represent that the cell would die next round.
