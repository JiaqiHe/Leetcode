# Problem
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```

## Idea 1
* We first read in the length of two lists, and we put the longer one at the first place.
* Start to add two lists by their true digit pairs (if l1 is longer, we simply add it to the result list). Here the sequence is 
special: put the new node ahead of the existing results.
* Last step is to handle carrying. Go through lists to solve carrying. Here the sequence is also special: put the new node ahead of 
the existing results.

## Idea 2
* read in two lists and push them into stacks
* each step, pop out numbers and add them to calculate the results
