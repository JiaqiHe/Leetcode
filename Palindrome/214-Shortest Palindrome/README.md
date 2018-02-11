# Problem
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

## Idea
We can interpret the problem in the following way:

Step 1: find the longest prefix which is also a palindrome

Step 2: Copy the rest of the string, reverse it and add it at the beginning.

Now we have to find a way to find the longest palindrome starting from the first character.

Generally, finding longest palindrome can be solved in O(n^2) time ([leetcode 5](https://leetcode.com/problems/longest-palindromic-substring/description/)).
Here, we have specific requirement that the palindrome has to start from the first character. We can use __KMP algorithm__ which is O(n) time
complexity to expidite the searching process:

* let S' = reversed version of S.
* use KMP on string `S + "$" + S'`
* the last value of KMP result is the longest length of prefix which is also a palindrome.
