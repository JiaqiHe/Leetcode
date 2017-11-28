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

## Idea 1

Treat this strings as nodes and imagine a graph, if two strings has only one different character, we then draw an edge between these two nodes.
Hence, after we represent every relations among those strings, we would get a graph. And our problem transforms into the following:

* Starting at the beginWord node, find the shortest path leading to the endWord node, if there is one.

This problem can be solved using BFS technique. We go level by level, to mark every node we visit, and check if we have arrived the end point.

## Idea 2

Bidirectional search!

Since we know the beginword and endword, we then can use bidirectional search. 

Steps are as follows:
* Transform data into unordered_set `list`
* Create two unordered_set `begin` and `end` to store begin level words and end level words
* We always take `begin` and find the next level words of `begin`
* We need to do two judgements: (1) if the word is in `end`, it means we have found the path, return step; (2) if the word is in `list`,
we then put this word into `nextlevel`
* How to manifast that we use bidirectional search? Here we go! Instead of always setting `nextlevel` to be `begin`, we make a comparision first: we compare the size of `nextlevel` with the size of `end`, and we choose the smaller one to be begin, and the other to be `end`. In this fashion, we always manipulate the unordered_set with smaller size, which is faster to compute.

