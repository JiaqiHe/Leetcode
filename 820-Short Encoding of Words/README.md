# Problem
Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:
```
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5].
```
Note:

* 1 <= words.length <= 2000.
* 1 <= words[i].length <= 7.
* Each word has only lowercase letters.

# Idea
这道题可以用Trie来做。从范例可以发现，问题可以转化为，将所有单词reverse之后，按照prefix分组，最后每组取最长的string出来作为该组的代表，即得到答案。

因此，在操作时，我们先reverse words，之后呢，构建trie，将这些words逐个加到trie中去。如果在加某个word的过程中都没有要添加任何一个新的node，那么说明这个
word被完全代表了，也就不需要为这个word重开一个组。只要有任何时候新加了一个node，就表明我们要新开一个组，并在最后的答案上加上这个word的长度。

问题来了！为了保证我们优先找到组别的代表，我们需要按照一定顺序进行添加words，即先添加长的，再添加短的。这样可以保证不会错误的为那些本可以被长的words覆盖
但却因为先被添加而加到了答案里去。

综上，这样的算法时间复杂度是O(nlogn)，其中n是words的长度。
