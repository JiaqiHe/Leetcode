# Problem
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
```
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

## Idea
This problem has similar idea to problem 46. Here, the extra trouble is that there are duplicates in the array, which would yield many
repetitive answers if we don't handle them at all. 

The idea is that, whatever the given array of numbers, we just care about how many cases for the first position, and the answer is straightforward,
simply the number of __distinct__ numbers in the array. So, instead of swaping every number to the very first, we add a process: __filtering__.
We only let those we never confronted in one iteration. The way I do this is brutal: I create a `unordered_set` for each iteration, and I keep
adding new numbers that we meet into that set, so that every time we can check the set to determine whether this number has ever occured or not.
