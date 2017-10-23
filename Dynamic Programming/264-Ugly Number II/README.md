# Problem
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

## Idea
This problem can be solved in a DP format.
 Let's find out how the array is formed. The first element is 1, which is equal to 2^0*3^0*5^0. We do this split and check if there is any secret:
 
 | Number        | 2     | 3        |5          |
|-------------|:--------:|:--------:|:--------:|
| 1     | 0 | 0 | 0 |
| 2     | 1 | 0 | 0 |
| 3     | 0 | 1 | 0 |
| 4     | 2 | 0 | 0 |
| 5     | 0 | 0 | 1 |
| 6     | 1 | 1 | 0 |
| 8     | 3 | 0 | 0 |

The first rows works pretty fine because every time only one factor number increases one. Seems a good strategy: 
* Every time we increase three prime numbers' occurance by one and select the smallest! 

However, things goes unexpectedly when we examine the number 6. Let's think about what yields 6. 6 is generated from (2,1,1) and we want 2 times 3.
Turns out 2 is dp[1] and 3 is dp[2]. We can utilize dp[ptr3]*3 to get what we want!

So the strategy is the following:

Set three pointers indicating the numbers of 2,3,5 in the number. Every time we do:
```
dp[i] = min(dp[ptr2]*2, min(dp[ptr3]*3, dp[ptr5]*5)) 
```
to get the number. After we find this value, we have to update the corresponding pointer.
