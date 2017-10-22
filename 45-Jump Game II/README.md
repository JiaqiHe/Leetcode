# Problem
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

## Idea
This problem can be solved by Greedy algorithm. The goal is clear, we need minimum times of jump to reach the end of the array.

So, the greedy algorithm is clear, each time we try to jump farthest. So we can implement this algorithm as the following:

a) standing at the beginning of the array, we know how far we can reach

b) we choose the "biggest jump" point from places we can reach

c) we depart from that biggest jump point to make another leap just as we did for the first point, every time we jump, we add one to the times of jump

d) repeat until we reach the end

In the alogrithm, we actually implement it in a roundabout way:

How to identify the "biggest jump" point in a leap? We can use a `priority_queue` to help us for one leap. When we go through all places, we 
push the jump distance into the priority queue. __BE AWARE__ that what we push into the priority queue is the relative jump distance, not the direct
value in the array, because we want to curve all inputs to be relative to the current ending point so as to know, starting from here, how far
can I reach for the next jump.

