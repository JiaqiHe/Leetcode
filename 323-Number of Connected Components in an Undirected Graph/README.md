# Problem
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
```
     0          3
     |          |
     1 --- 2    4
```
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
```
     0           4
     |           |
     1 --- 2 --- 3
```
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

## Idea 1
Union-Find Algorithm. 

We create a `parent` vector to store the connection info. To begin with, we __initialize each node's parent to be itself__. We go through
every edge to unite nodes. After we go through all edges, we still need to __update the parent vector for the last time__ so that the number of
different parents can be the smallest. We then output that number.

## Idea 2
DFS.
We can treat this problem as a graph problem. First we need a representation of this graph. Here we use adjacent lists. Since it's undirected,
when we update adjacent lists, we might as well __treat every undirected edge to be two directed edges__. We also need a vector `visited` to
record the status of each node whether we have visited it or not. Then we can use dfs to find connected components. We iterate through all nodes
and if the node is __not__ visited, we then do dfs starting from this node. What dfs does is modifying every connected node's `visited` to be 
true.

However, my dfs code would TLE for large inputs, I don't know why.

## Idea 3
BFS.
Similarly, we can use BFS. We use a queue instead to store next level of nodes, and process them accordingly.

Luckily, BFS code gets accepted :)
