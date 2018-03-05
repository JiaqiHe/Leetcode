# Problem
Implement wildcard pattern matching with support for '?' and '*'.
```
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
isMatch("aaac", "aa*") → true
```

## Idea
* dynamic programming
* dp[i][j]表示s的前i个字符和p的前j个字符的匹配情况：true 匹配成功；false 匹配失败
* 状态转移方程是什么样的呢？
* 假设我们要求dp[i][j].会有以下情况：
* （1）p[j-1]是普通字母，那么只有p[j-1] = s[i-1] 且 dp[i-1][j-1] = true 才能设置为true
* （2）p[j-1]是？，那么只要dp[i-1][j-1] = true，就设置为true
* （3）p[j-1]是*，由于*的多重含义，情况也就复杂了。
    * 情况一：我们将*理解为空，那么只要dp[i][j-1]为true即可。
    * 情况二：我们将*理解为多个字符，那么我们就要求dp[i-1][j]为true
