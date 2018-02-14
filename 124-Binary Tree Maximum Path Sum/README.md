# Problem
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,
```
       1
      / \
     2   3
```
Return 6.

## Idea
Since the "path" is not restrictedly defined, we should be aware of the data passing in recursion. If we directly pass the path that has the largest value and passes this node, we actually cannot utilize this information because the parent node has to know what this path looks like and make decisions based on that. Hence, in order to ease this trouble, we should uniformly provide the length that can be directly used by the parent node. Namely, we pass the length of the path which starts at certain node.

In this way, the parent node can decide whether to concatenate the left path or the right path or both or neither. This subtle difference would lubricate the recursion efficiently.
