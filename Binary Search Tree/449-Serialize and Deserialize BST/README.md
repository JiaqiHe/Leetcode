# Problem
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

## Idea
For any type of tree, we can construct the tree if we know two traversals out of three (in-order, pre-order, post-order).

Here, we have a Binary Search Tree, so we actually can use only one traversal result to reconstruct the tree. Why? If we know the pre-order 
traversal result, we then can know the following:
* the first element is the root of BST
* for all the following elements, those whose values are smaller than the root, they are components of the left subtree; similarly, those whose
values are greater than the root, they are the components of the right subtree. And More importantly, they are automatically divided into two
parts because of pre-order: left(smaller) elements always comes first, then right(larger) elements. 

We then can reconstruct the tree recursively. Let's confirm what steps are to be compteleted in each recursion.
* create a `root` node
* seperate the following elements into two parts
* for each part, we call recursive function, return the value to `root->left` and `root->right`
* return `root`
