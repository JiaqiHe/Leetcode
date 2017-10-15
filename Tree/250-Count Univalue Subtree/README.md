# Problem
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

## Idea 1
Do it in recursive way. How? We can do this in a post-order traversal. The reason why we choose post-order is that
we need info from subtree to simplify work for the nodes that are higher. We keep calling that function for left and right subtree if any.
Then we do the work about the node we currently visiting. Notice here that thanks to the benefit of post-order, we are guaranteed to have info
of the node's subtree (whether the subtree is a uni-value subtree or not). Then the work is quite simple:

* if there is a left/right tree, then it left tree should be a uni-value subtree and the left node's value should be equal to the node
we are currently at. If so, we have found another uni-value subtree!
* if there is not, never mind, it's a leaf, of course it's a uni-value subtree!

So the judging condition is represented as follows:
```c++
 if((root->left == NULL ||(root->left && root->val == root->left->val) && dict[root->left]) &&
    (root->right == NULL ||(root->right && root->val == root->right->val) && dict[root -> right])){
           res++;
           dict[root] = true;
        }
```
Just as shown above, `dict` is a `unordered_map` to store any uni-value subtrees.

## Idea 2
Also do it recursively. We establish a function `compare` that returns boolean to help us do the math and continue calling recursive function nicely.
This function does the following:
* It determines whether the node we are currently at is a uni-value subtree or not.
So, if it has a left node, we should call `compare` for left node and get return of whether its left subtree is a uni-value subtree; besides, we
need to compare if the root has the same value with its left node;

samely, for right node, we do the same thing.

We then can combine all necessary judgements together and increase the result if needed.
