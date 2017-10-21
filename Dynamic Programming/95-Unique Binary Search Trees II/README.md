# Problem
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```
## Idea
This problem is related to Unique Binary Search Trees. However it is not easy to implement it using same technique - DP. Why? Because for each
n, the elements in the tree is different, no way to directly use the previous results.

For this problem, we can simply use recursion. Since 1,2,...,n is the in-order traversal of a BST, we can choose a number as a root, and the left
part should be left subtree, and right part should be right subtree. This is exactly the pattern of recursion. This recursive would return a 
vector<TreeNode*> and we have to combine the left subtree results and the right subtree results to generate the whole tree.
