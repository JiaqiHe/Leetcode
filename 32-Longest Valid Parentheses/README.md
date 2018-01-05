# Problem
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

## Idea 1
We can use __Dynamic Programming__ to solve this problem.

Define a vector to store dp results.

`dp[i]` represents the length of the longest valid parentheses ending at character with index i.

Hence,  `dp[i]` = 0 for all `s[i]` = '('.
if `s[i]` = ')', we need to analyze its situation. First , check dp[i-1] so as to know the length of longest valid parentheses ending
at index i-1. Based on this, we want to figure if it can extend the length. What's the criteria? The rule is that, we need to
confirm that it has a '(' right before the beginning of that longest substring. That's to say, s[i-pre_len-1] has to be valid and it has to be equal to be '('.
What's more, we need to take care of the previous cases as well if i-pre_len-1 > 0 by simply adding dp[i-pre_len-2].

## Idea 2
We can use a __stack__ to tackle this problem. If we do the standard push and pop for this string of parentheses, what are left
in the stack are definitely those parentheses that cannot be matched. If we know their indexes, we can then calculate the longest
valid parentheses because the interval between two indexes in the stack must be valid. we then take out the largest.
