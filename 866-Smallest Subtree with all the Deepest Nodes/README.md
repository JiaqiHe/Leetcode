## Problem
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in it's subtree.

## Idea
要找子树里包含所有最深叶节点的node，换言之，就是要找所有最深叶节点的lowest common ancestor(LCA)。如果这么看的话，就先锁定最深叶节点，然后call LCA。
在求LCA的时候，传最左侧和最右侧的最深节点就行了。
