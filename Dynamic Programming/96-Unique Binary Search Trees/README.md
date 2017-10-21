# Problem
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.
```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

## Idea
This problem looks intimidating because it involves with tree structure. However, since it specifies BST, then we should know that 
BST can be transformed into pre-order or post-order traversal without losing any information. Hence, instead of trying to construct
BSTs, we might as well try to construct arrays that can be pre-order/post-order traversals.

Let's use pre-order traversal as our target. Due to the property of BST, the pre-order sequence of a BST would form perfectly into the
following pattern:
* (first element a) (elements smaller than a) (elements larger than a)
This might indicates the DP idea to solve this problem. If we settle down the first element, then the rest of the work is:

* for the elements smaller than the first element, they should form a BST as well, namely they should also satisfy the pattern. This clutser 
has fewer numbers and if we use DP, we can get its result directly without calculating again.
* same thing for the elements that are larger than the first element.

Ok, the DP idea is clear.
