# Problem
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
```
    2
   / \
  1   3
Binary tree [2,1,3], return true.
```
Example 2:
```
    1
   / \
  2   3
Binary tree [1,2,3], return false.
```

## Idea 1
Just as [Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/description/), we create a struct to return 
data that we retrieved so as to help recursion. Also, do it in a post-order fashion.

## Idea 2
Since the benefit of BST, we know that the in-order sequence of the BST has to be sorted and strictly monotonic. Hence, we can
solve this problem by simulating in-order traversal. Every time of getting a value, we compare it with the previous number. The 
tree is BST iff the numbers we get follow an increasing pattern.
