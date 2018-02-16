# Problem
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
```
         1
       /  \
      2    3
     / \    \
    4   5    7
```
After calling your function, the tree should look like:
```
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
```

## Idea
The idea is to populate next pointer level by level. When we update kth level, we would need (k-1)th level to help us.

We create a dummy node as guard. First, the root pointer would go over (k-1)th level's node one by one, at each node, we check whether
it has left/right node or not. If so, we add them in order to the dummy node's next pointers and form a series of this level. When
the root pointer goes to NULL, namely the end of (k-1)th level, we know we have completed the population of kth level. 

At the end, substitute the root by dummy->next, and redo the process.
