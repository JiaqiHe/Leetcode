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

## Idea 1
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

## Idea 2
__Shunting-yard algorithm__ and __reverse polish notation(RPN)__.

We can transform infix expressions into postfix notation string (RPN) and evaluate the transformed string.

Details about shunting-yard algorithm (from Wikipedia):
```
while there are tokens to be read:
	read a token.
	if the token is a number, then push it to the output queue.
	if the token is an operator, then:
		while ((there is an operator at the top of the operator stack with
			greater precedence) or (the operator at the top of the operator stack has
                        equal precedence and
                        the operator is left associative)) and
                      (the operator at the top of the stack is not a left bracket):
				pop operators from the operator stack, onto the output queue.
		push the read operator onto the operator stack.
	if the token is a left bracket (i.e. "("), then:
		push it onto the operator stack.
	if the token is a right bracket (i.e. ")"), then:
		while the operator at the top of the operator stack is not a left bracket:
			pop operators from the operator stack onto the output queue.
		pop the left bracket from the stack.
		/* if the stack runs out without finding a left bracket, then there are
		mismatched parentheses. */
if there are no more tokens to read:
	while there are still operator tokens on the stack:
		/* if the operator token on the top of the stack is a bracket, then
		there are mismatched parentheses. */
		pop the operator onto the output queue.
exit.
```

Algorithm that evaluate RPN expressions:
```
for each token in the postfix expression:
  if token is an operator:
    operand_2 ← pop from the stack
    operand_1 ← pop from the stack
    result ← evaluate token with operand_1 and operand_2
    push result back onto the stack
  else if token is an operand:
    push token onto the stack
result ← pop from the stack
```
