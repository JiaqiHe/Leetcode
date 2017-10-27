# Problem
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
```
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```
Example 2:
```
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
```

## Idea
Recursion! For each TreeNode, there are two cases for the theif to rob houses:
* rob this house, and therefore for those houses that are directly connected to this house cannot be robbed, namely the thief cannot rob the node's children.
Instead, the theif goes to the children's children's nodes and start to maximize his interest. Here is the thought of recursion.
* do not rob this house, instead, rob this node's children

Ok, we can design a recursive function to tackle this problem. Just as analyzed above, the output should be the max money the thief can rob from one
node. In the function, we have to implement the two cases:

```c++
    int robhelper(TreeNode* root) {
        //base cases
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            res = max(res, root->val);
            return root->val;
        } 
        //don't rob root
        int con1 = robhelper(root->left) + robhelper(root->right);
        //rob root
        int con2_1 = 0;
        int con2_2 = 0;
        if(root->left) con2_1 = robhelper(root->left->left) + robhelper(root->left->right);
        if(root->right) con2_2 = robhelper(root->right->left) + robhelper(root->right->right);
        int con2 = con2_1 + con2_2 + root->val;
        res = max(res, max(con1, con2));
        return max(con1, con2);//return the max money thief can rob instead of res
    }
 ```   
