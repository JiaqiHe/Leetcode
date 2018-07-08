## Problem
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in it's subtree.

Example:

Input: [3,5,1,6,2,0,8,null,null,7,4]

Output: [2,7,4]

Explanation:

![image](https://github.com/JiaqiHe/Leetcode/blob/master/866-Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/sketch1.png)
```
We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.
``` 

Note:

* The number of nodes in the tree will be between 1 and 500.
* The values of each node are unique.

## Idea
要找子树里包含所有最深叶节点的node，换言之，就是要找所有最深叶节点的lowest common ancestor(LCA)。如果这么看的话，就先锁定最深叶节点，然后call LCA。
在求LCA的时候，传最左侧和最右侧的最深节点就行了。
