# Problem

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

## Solution

This problem can be solved using deque. Deque is short for "double-ended queue". Double-ended queues are sequence containers 
with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

We utilize deque to accomplish the following:

a) make sure the elements in the deque is in descending order

b) make sure the front element is within the window with width k

If we managed to do this, we can easily know what number is the maximum number in the current window, simply the front element!

## Steps

* To implement a), we do the following: check elements at the back of the deque, if it is smaller than the current element, pop it out!
Why? Cuz it would never have a chance to become a maximum number( the current element comes after the element we popped out and therefore, for
every window containing these two elements, the smaller one would never got a chance.) We do so repetitively until the back element is larger
or the deque is empty. After Trimming small elements, we now can put current element into the back of deque.

* To implement b), we do the following: if the current index - the window size = the front index, meaning it is out of the range of the window.
We need to pop it out!
