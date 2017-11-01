# Problem
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.

Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

## Idea
For problems that only one element appear once and all other elements appear twice, we can use XOR to solve this problem easily. However, this
problem has two elements that appear once. We can harness the similar idea.

We might as well count every bit's occurance. Since those two elements are not the same, hence one of them must contribute to certain position
such that the counting result is not a multiple of 2. In this case, we find all elements which contribute 1 to that position, do XOR in that group
and we can get the unique element. 

If we know one element, we can easily calculate the other one. If we know the XOR result of them, we do XOR again and we can get the second element.
