# Problem

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"

endWord = "cog"

wordList = ["hot","dot","dog","lot","log","cog"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",

return its length 5.

## Ideas

Treat this strings as nodes and imagine a graph, if two strings has only one different character, we then draw an edge between these two nodes.
Hence, after we represent every relations among those strings, we would get a graph. And our problem transforms into the following:

* Starting at the beginWord node, find the shortest path leading to the endWord node, if there is one.

This problem can be solved using BFS technique. We go level by level, to mark every node we visit, and check if we have arrived the end point.

