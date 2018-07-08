## Problem
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:
```
Input: 6
Output: 7
```
Example 2:
```
Input: 8
Output: 11
```
Example 3:
```
Input: 13
Output: 101
``` 

Note:

* 1 <= N <= 10^8

## Idea
此题要求有二，prime + palindrome。个人感觉判断prime的cost要大很多，因此为了减少判断prime的次数，把该条件放到最后来判断：只有通过了是palindrome且比
N大的条件，我们才检测是不是prime。

如此，我们需要做两件事：找到palindrome，判断prime。

* 这里找palindrome可以联想到之前leetcode有一题，找next palindrome。具体实现就是取已知palindrome的一半，然后+1，主要要考虑会有进位的情况。

另外就是判断prime。




