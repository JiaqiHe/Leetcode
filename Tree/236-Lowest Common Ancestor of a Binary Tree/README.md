# Problem
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
```
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
```
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a 
descendant of itself according to the LCA definition.

## Idea
We often use __recursion__ to tackle tree problems, this problem is still no exception. Our task is to find LCA. Let's first find out what property does LCA
have. 

First, if, somehow, we know the two TreeNodes are seperately located in the left and right subtree of one certain root, then we can draw the conclusion
that this root is the answer, their LCA because there is no other TreeNodes that connects the left tree and right tree except itself and its ancestors.

Second, if, somehow, we know the two TreeNodes are located in the left/right subtree of one certain root, then we know that the answer must reside
in the left subtree as well! We don't need to care about the right subtree at all.

So, based on the two mentioned discoveries, we can design a recursive algorithm shown as follows:

* We set the base case: if the root is NULL, the root is the same as p, or the root is the same as q, we return this TreeNode. So our recursive function
will only return when we meet the end (NULL) or we meet our first target (no matter which TreeNode as long as we meet one of them first).
* We call this function for the left subtree, let the answer returned be `left`
* We call this function for the right subtree, let the answer returned be `right`
* Then we can draw our conclusions:
* if `left` and `right` are both __NOT NULL__, we know that p and q must seperate into left and right subtree, and we know their LCA is the root
* if `left` and `right` is __one NULL and some TreeNode the other__, and we know that two TreeNodes are in the same subtree, and we have known that
the returned TreeNode is the first TreeNode we come across, and this is exactly the answer.
* if `left` and `right` are both __NULL__, then it actually never happens, we can simply return NULL.

We can implement this in a simple recursive way or in a Divide and Conquer way.
