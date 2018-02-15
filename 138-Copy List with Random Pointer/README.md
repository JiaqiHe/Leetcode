# Problem
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

## Idea1 - O(1) extra space
The main idea is to utilize original's random node to save its corresponding copied node.

step 1:
```
________________________________________
original                    copy
next         /-------------->next
random  ----/               random
________________________________________
```
step 2:
```
________________________________________
original             /-------copy
next                /       next
random <-----------/       random
________________________________________
```
step 3:
propogate random nodes in copy

Step 4:
propogate next nodes in copy (The reason why we can do this is that next node comes out in order. Suppose we are doing kth node, then
its next node is (k+1)th node, and we haven't process that node yet, and its random node is still working as a pointer to its
corresponding copied node)

## Idea2 - O(n) extra space
simply use unordered_map to pair original nodes and copied nodes.
