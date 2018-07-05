## Problem
Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:
```
Input: A = "ab", B = "ba"
Output: 1
```
Example 2:
```
Input: A = "abc", B = "bca"
Output: 2
```
Example 3:
```
Input: A = "abac", B = "baca"
Output: 2
```
Example 4:
```
Input: A = "aabc", B = "abca"
Output: 2
```

Note:

* 1 <= A.length == B.length <= 20
* A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

## Idea
先把没有配对的字符以及它所在的index信息整理出来，放到一个map里去。然后从没有配对的这些字符中去找有没有你情我愿的pair，也就是这两个字符互换一下就皆大欢喜
那种。如果有，就把他们换一下。如果在遍历完之后仍
