# Problem

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

## Idea
Union-Find algorithm.

The requirement of O(n) complexity limits us to use sorting. We then can use `unordered_map` to solve this problem using union-find.

The reason why we need a map is that we need to know which number in the array has been visited or not, and the numbers can vary drastically,
so we use `unordered_map` instead of `vector`. Hence, this `unordered_map` would be a int -> bool map.

The algorithm is as follows:
* iterate each number `x` in the given array, do the following:
* set counter as 0. If the number `x` is not visited, we then increase counter by 1. Else, return (because we have completed its expansion previously when we expand other numbers). Then expand on both sides of this number, namely we try to find if `x-1` and `x+1` are in this array. If so, we mark this number as visited, and 
increase counter accordingly. If we don't find it in the given array, we then immediately stop to search in that direction, return the current
counter.
* we take the maximum of all returned counters and that is the result.
