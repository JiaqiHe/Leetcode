# Problem
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

## Idea
One way of doing this is to do a in-order traversal so as to transform a BST into an array, then problem becomes very easy: we only need to find 
the kth smallest element in a sorted array, namely the element with index k-1(0-based array).

However, we can do it more efficiently. We apparently don't need the whole array, we just care about the first k elements. We can accomplish
this using an iterative way of in-order traversal. 
* use a stack to store elements that we have visited but not yet to be checked
everytime we find the smallest element, we check how many elements we have found, if we have found k-1 elements, then the element we found this
time is the answer! Break out the loop and return it immediately!
