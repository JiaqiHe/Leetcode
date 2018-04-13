## Problem
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```
Example 2:
```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```
## Idea
Binary Search.
不用考虑edge case（i=0 或者 i=m 或者 j=0 或者 j=n）。一旦有这种情况出现，那么此时的i和j一定是答案了。为什么呢？因为i和j都是从最中间开始的

如果有一个变成了其中一种edge case，那么一定是“历史的选择”，也就是说，之前的所有判断都迫使其走向这个edge case，然而一旦走到这个edge case，就到头了

所以这些edge case都是答案，都在最后的else break处理, 这也使得binary search的条件可以写的如此简洁，只要保证不等式的前提成立，以及不等式本身成立即可
