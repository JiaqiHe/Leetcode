# Problem
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
```
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
```
Notes:
You may assume both pattern and str contains only lowercase letters.

## Idea
For this problem, we need to use two dictionaries to ensure the property of bijection.

The task is to assign substrings to each character in pattern so as to fit the match.
Starting from the first character, we try all substrings with different lengths to be the match with it. Then match the next character.

The ending condition is we reached the end of pattern and str simotaniously. When we find collisions, we continue to try next substring with 
different length.
