# Problem
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
```
Input: 12
Output: 21
 ```

Example 2:
```
Input: 21
Output: -1
```

## Idea
This problem requires manipulating digits. We first split the number into digits to start with.

How to find the next number that is greater than the original and yet it is the smallest among all others? The idea is the following:

Starting from the ones digit, we trace to higher digits. If the order is increasing, for example, 21, which goes from 1 to 2, we know that for these two digits there's no way to find an interger satisfying the limits because that is the largest form of using 1 and 2. So, our goal is to find the first position that breaks this rule.

After finding that position, we need to swap a new digit to the target position using a slightly greater number. So this time our mission is to find the smallest digit that is greater than this digit and swap them. 

Lastly, in order to get the smallest answer, we sort the rest of the digits such that it decreases if we look from ones digit to the higher digit.

Also, check the validity of the answer to see if it is within the boundary of INT_MAX.
