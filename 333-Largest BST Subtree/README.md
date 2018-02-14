# Problem
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
```
    10
    / \
   5  15
  / \   \ 
 1   8   7
 ```
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?

## Idea
To determine whether or not a tree is BST, we would need many info like:
* left subtree's max value
* right subtree's min value
* whether left subtree is a BST
* whether right subtree is a BST
* BST's size

Therefore, we might as well create a structure to return these info as a group. We can do this problem in a post-order manner 
because of the natural attribute of BST. If the tree is BST only if the subtrees are BST. We can make decision only if we know
everything about the subtrees.
