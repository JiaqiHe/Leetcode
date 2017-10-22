# Problem
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
```
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
```
## Idea
Somehow, this problem is Greedy! We do the following:
* Every time, we select the highest group of people, and we consider placing them first. Since they are the tallest, then no one can be taller
than them. So what? It means the index that comes along with them is their position. We then, as their indexes indicate, place them accordingly.
* Then move to the next group of the tallest people. Same thing as we do for the previous bunch of people.
* Keep doing this until we have placed all people.

Why is that? Let's think of this problem in this way. For each group, we actually want to maintain their order first in their small group. Besides,
since we start from the tallest, then when we start to arrange another group of people, all the people that are already placed are taller than the
guy we want to arrange. Therefore, when in insert the guy according to his index, we can guarantee that in front of him there are exactly (how many) 
guys. What's more, inserting a shorter guy doesn't affect those people who are already in line, because only those whose heights are taller
matter.
