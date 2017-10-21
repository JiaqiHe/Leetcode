# Problem
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

## Idea 1
One way of doing this problem is to use two arrays: left and right to save useful information. We define left[i] and right[i] as follows:
* left[i] represents the closest index k in the left-hand side of the element with index i such that nums[k] < nums[i];
* right[i] represents the closest index k in the right-hand side of the element with index i such that nums[k] < nums[i].

In order to achieve O(n) time complexity, we cannot do it in a naïve way, going step by step from the original point. The trick is as long as we have saved the answers that we have calculated, we can utilize those answers to make a leap when possible so as to avoid unnecessary comparisons.

Say we want to calculate left[i], so first check if nums[i-1] is larger than nums[i]. If so, we don’t dumbly check nums[i-2], instead, we go directly to index left[i-1] because when we calculate left[i-1], we have found out which index is the closest that satisfies the property. So we check nums[left[i-1]] to avoid unnecessary work. If nums[i-1] is smaller than nums[i], then we simply set left[i] as i-1.

In this way we can achieve an O(n) method to complete left[] array and similarly, the right[] array.

The left work is pretty straightforward since we have acquired necessary information. We just need to traverse all elements and calculate 
the area of a rectangle with the width of its value. The length of this rectangle depends on left[i] and right[i], and equals to right[i] 
– left[i] -1. During the traversal, we keep updating the maximum area. We can finally acquire final results when this traversal is 
completed. The overall time complexity is O(n) as well because we just traverse the array for three times and each operation is constant
time.

## Idea 2
Another way is to use a stack to save the index of each vector entry in a ascending order; once the current entry is smaller than the one 
with the index s.top(), then that means the rectangle with the height height[s.top()] ends at the current position, so calculate its area 
and update the maximum.

The only trick here to avoid checking whether the stack is empty (due to pop) and also avoiding emptying the stack at the end (i.e. after going through the vector, s is not empty and we have to consider those in the stack) is to put a dummy "0" at the beginning of vector "height" and the end of "height": the first one makes sure the stack will never be empty (since all the height entries are >=0) and the last one will flush all the remaining non-zero entries of the stack at the end of "for" iteration. This trick helps us keep the code concise.
