# Problem
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation: 
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.

Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].

## Idea 1
* bucket sort一下，得到不同的数字以及出现次数
* 接着，制作这样一个map，number->points，表示的含义是：从number开始选能得到的points
* points初始化为number * 出现次数
* 从最大的数往前走，逐个更新points，原则是：查比当前数字大1的那些数，从中挑一个points最大的，加到points上
* 最后这些points中的最大值即为答案

## Idea 2
* bucket sort一下，得到不同的数字以及出现次数
* 创建take和skip，含义是：从到index为i的数中选，且take该数和skip该数的最大points
* 最后的答案是take和skip的最大值
