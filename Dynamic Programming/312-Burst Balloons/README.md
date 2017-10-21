# Problem
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167
```
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

## Idea
This problem has very latent connection with DP. Let's scrutinize the problem for clues.

As the problem suggests, we might as well add two 1s at the beginning and the end of the array. Every time we burst a balloon, the array would shrink by one element visually. But what really matters are the elements that would be 
adjacent. If we can figure out the adjacent elements, we actually don't need to literally delete the balloon. 

We let dp[i][j] represent the maximum result of the subarray with index [i,i+1,...,j]. What's the benefit of storing this information?
With this info, we can treat the subarray with index [i,i+1,...,j] as a subproblem, and when we need to calculate, say dp[i][j+1], then 
we can utilize the info: there are (j+1-i+1) possible ways to burst a balloon as the last balloon, and if we decide to burst balloon k at the end, then we can easily calculate
the result: 
```
dp[i][j+1] = nums[i-1]*nums[k]*nums[j+2] + dp[i][k-1] + dp[k+1][j+1]
```
Why is that? You can first burst balloons from i to k-1 and you get results saved at dp[i][k-1], then you burst balloons from k+1 to j+1 and 
you get results saved at dp[k+1][j+1], and finally you have only one balloon with index k, and the left balloon is the balloon with index i-1, and 
the right balloon is the balloon with index j+2.

So we should first calculate those short subarray results, and then long subarrays, and finally we get the answer:

```dp[1][len(original array)]```
