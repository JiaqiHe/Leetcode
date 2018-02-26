# Problem
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

Example 1:
```
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
```
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
```
[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]
```
On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
Example 2:
```
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
```
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:
```
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
```
Explanation: The region on the left only builds two new walls.
Note:
* The number of rows and columns of grid will each be in the range [1, 50].
* Each grid[i][j] will be either 0 or 1.
* Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.

## Idea
模拟整个过程
* 第一步：统计病毒区域以及能够扩散的数量
* 第二步：选出扩散能力最强的那个群体
* 第三步：计算需要多少面墙，同时将这些被隔离的病毒标记成“被隔离”
* 第四步：对于其他病毒区块，进行病毒传播
* 如此往复
*
     
符号规定：
* 1 - 未被控制的病毒
* 0 - 未被感染的人群
* 2 - 已被隔离的病毒
* 5 - （中间状态）统计病毒区域时被访问过的病毒
* 3 - （中间状态）计算墙时被访问过的病毒
