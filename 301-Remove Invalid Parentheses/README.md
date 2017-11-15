# Problem
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
```
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
```

## Idea
We can use a stack or a counter to examine the validity of a string of parentheses. In this problem, we not only need to examine it, but rectify
it. So, intuition is: every time we find the first invalid parenthesis, we stop going further, and try to fix this parenthesis.

Say we want to check ). When we first see that the number of ) is larger than (, we know one right parenthesis should be eliminated. How many
possible ways to delete a right parenthesis? Intuition tells us that how many right parenthesis in the string that we have checked, then we hanve 
that number of possible ways to delete a closed parenthesis. However, we may have dupicates when there are contiguous )) in the string. Since we 
only need to delete one parenthesis and we only have to delete one (because as soon as we find that the number of ) is larger, we would stop,
and by that time, there is only one extra ) that needs to be deleted). So for the contiguous case, we delebrately only deleting the first one
so that we won't produce duplicates.

And, it's not done. We haven't taken care of ). We also need to check if there are any extra ( to delete. One TRICK is to reverse the string,
and do it the same way we do for ). And we are all set.

To recap, the idea is as follows:
* take care of extra )
* reverse the string
* take care of extra (
* for those which successfullly reach this step, save 'em to the results.
