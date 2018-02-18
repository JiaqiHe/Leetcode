# Problem

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

## Idea
Even O(nlogn) time algorithm cannot pass. We have to think of an O(n) time algorithm.

The idea is to directly compute the element that needs to be added into the result. So what is the rule?

The answer is always starting from 1. Say the current number is represented as `cur`. What's the next one? We first try to add "0", namely test if
`cur * 10` is within boundary. If this fails, we then try to add "1","2","3",... at the tail, namely `cur + 1`. What needs to be
noticed as well is, every time we get a number ending at "0", we should delete it because of the lexicographical order. We would 
retrieve these "0"s later.

In such a way, we can solve this in O(n) time and O(1) space.
