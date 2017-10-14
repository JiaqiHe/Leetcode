# Problem
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys __less than__ the node's key.
* The right subtree of a node contains only nodes with keys __greater than__ the node's key.
* Both the left and right subtrees must also be binary search trees.

## Idea 1
One way of doing this is to iterate the tree in in-order traversal to check if the sequence we get is a monotonic increasing array. Why? Because 
of the unique property of a BST: BST is originated from binary search. There is kinda a reflection between binary search and BST. So if we do
the reverse operation, namely transforming a BST to a array in in-order traversal, we should get a sorted array. Hence, if the array is not
strictly in ascending order, we then draw the conclusion that the tree is NOT a BST.

## Idea 2
Another way is, to implement in-order traversal element by element, and for every element we find, we immediately validate its value to see if
it is larger than the previous one. 

So this requires the iterative version of in-order traversal, which is problem #94. The pivotal idea is the following: 

use a __stack__ to store nodes we have visited but not yet ready to be checked

Owing to in-order traversal, we have to keep going left until we meet the "dead end", namely `NULL`. We then can take the top node out, to check
its correctness. How to check its correctness? Just compare it with the previously checked node, so we need a __pointer__ to save the previous node
as well.
