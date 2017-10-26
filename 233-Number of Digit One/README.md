# Problem
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

## Idea
This problem can be solved in DP manner, but it won't work out for large n. So technically we have to find out the math behind it.

Let's examine some toy examples: 37, 137, 237, 337, 437. Why these examples? Well, if we can find the connection between n-th digit number and
(n-1)th digit number, we can solve this problem in a recursive manner.

Ok, first, for 37, we know the output should be 14.

For 137, let's analyze this number. 137 covers all 2-digit numbers and 1-digit numbers, namely numbers from 1 to 99, how many 1s are there in these 
numbers? The answer is straightforward: 20. Think like this: we first calculate how many 1s on ten's digit. we set ten's digit to be 1, and we
have a vacant place for the one's digit, apparently, there are 10 choices from 0 to 9. Similarly, there are also 10 choices for ten's digit when
we set one's digit to be 1. So there are 20 1s for numbers from 1 to 99.

And then, we have to count 1s in numbers from 100 to 137. Let's first count the hundred's digit. Apparently the number of 1s on hundred's digit is 
equal to the number of numbers from 100 to 137, so that's 38. And yet we still have ten's and one's digit to count. And Turns out since the hundred's is
1, then the maximum 2-digit number in the 3-digit number neglecting the hundred's digit is 37. We can use the answer of counting 37, namely 14 in this
case. So the output should be 20 + 38 + 14.

For 237, same analysis. First for 2-digit numbers and 1-digit numbers, namely numbers from 1 to 99, there are 20 1s. For numbers from 200 to 237, the hundred's digit
shall never be 1, so we only need to care about the ten's and one's digit. Again, that's the result of 37, 14. For numbers from 100 to 199, we know there are
100 3-digit numbers here, so the number of 1s on the hundred's digit is 100. For their ten's and one's digit, they can go from 1 to 99, so again, 20.
Overall, the output is 20 + (100 + 20) + 14.

Similarly, for 337 the output is 20 + (100 + 20) + 20 + 14;

for 437 the output is 20 + (100  + 20) + 20 + 20 + 14;

...

Hence, we can know the pattern here. To clearly state the pattern, we name several variables:
```
the number of digits of the input `n`: `digits`
the number of the first digit of the input: `first`
n/10 : `remain`

res = `first`==1? `remain`+1 : pow(10, `digit`-1 + `first`*n_digit_max[`digit`-1] + countDigitOne(`remain`);
```
where n_digit_max[i] is the number of 1s in the numbers from 1 to the maximum of a i-digit number, which is supereasy to calculate, namely `n_digit_max[i] = i*(pow(10, i-1))`.



PS. example for 2-digit numbers:
```
       1             _   
ten's digit     one's digit
                 10 choices
                 
       _              1
ten's digit     one's digit
   10 choices
```
