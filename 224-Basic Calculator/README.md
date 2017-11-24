# Problem
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
```
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
```
Note: Do not use the eval built-in library function.

## Idea
The general idea is to use stacks. Every time we encounter "(", we push current result and current operation sign to corresponding stack, and reset the variables; Every
time we encounter ")", we know that we have finished this nested part, we take out the top-level elements in the stacks, and do calculations to combine answers.

Details are shown below:

We create `res` to store results, `num` to store current number, `sign` to store current operation sign, and two stacks `nums` and `ops`.

Keep in mind: we always first find an operation sign, and then we find a number following this sign. If we have both, we can do calculations, 
at least for this pair.

If current char is a digit, we then update `num`; if not, we must have encounterd "+/-/(/)" and this means we have find a complete
pair for us to do some calculation (we know the sign and the number), so we update `res` accordingly and reset `num` to be 0. 
We can then start to find next part. Apart from updating `res`, we have other work to do for different cases:
* if it's '+', we know for the next pair, its sign should be 1, update `sign` to be 1
* if it's '-', we know for the next pair, its sign should be -1, update `sign` to be -1
* if it's '(', we know that we need a brand new start. Before we clear all variables, we first push valuable info that we acquired into the 
stack, and then initialize them accordingly.
* if it's ')', we know that we have finished calculating the nested part of calculation and the result of this part is stored in `res`, and 
we need to combine this result with the former answers that have been pushed into the stack. So take them out, and do some math.

Another thing to notice is that we only add `num` into `res` only when we encounter "+/-/(/)", what if the end char of the string is simply 
digit, if so we don't add the last number into the result. Hence we need `res += sign * num` at the end. This is also safe for other cases because
we reset `num` to be 0 and the last step won't affect them.
