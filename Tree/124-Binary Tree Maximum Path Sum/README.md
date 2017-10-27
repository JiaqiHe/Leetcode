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
This problem can be solved by recursion, but in a tricky way.

Let's analyze how this path would form first. The goal is to find a path and if we add up all the elements on that path, we should get maximum
sum. Well, so far, designing a selecting creteria seems to be no clue, we might as well go over every node, find a path that goes throngh this node
and yield its max, we select the max among these max, and finally we can get final max sum!

So let's think about the conditions for a path passing one node. There are 4 cases for that:
* 1. That path contains only that node
* 2. That path is formed by the node and a path in its left subtree
* 3. That path is formed by the node and a path in its right subtree
* 4. That path is formed by the node, a path in its left subtree and a path in its right subtree

So, for each node, we just take the max from these 4 cases and we are done for this node.

But question is, what shall be the output of our recursive function? By analyzing the upper 4 cases, we find that what we need is not the max sum 
of children's nodes, we simply need a path that only originates from the node, not one that goes through it! This tells us that our output of
the function cannot be the max sum of one node, it should be __the max sum of one path that originates from the node__, namely the first three conditions'
max value!!!!

If we get this point clear, we then can easily construct our recursive function. Since we need the final max, we can update the real max sum within
each call. Therefore, our recursive function looks like below:
```c++
int helper(TreeNode* root, int &res){
        if(root == NULL) return 0;
        int l = helper(root->left, res);
        int r = helper(root->right, res);
        int max_single = max(max(l, r)+root->val, root->val);
        int max_double = max(max_single, l+r+root->val);
        res = max(res, max_double);//update the max within the recursive function
        return max_single;//return the max sum of the path that originates from the node
    }
 ```

