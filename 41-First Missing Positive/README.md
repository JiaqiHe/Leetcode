# Problem
Given an unsorted integer array, find the first missing positive integer.

For example,
```
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
```
Your algorithm should run in O(n) time and uses constant space.

## Idea
The idea is tricky. For every element, we want to place them to such a place that after the process, the array is sorted to some
extent.

Since we want to find the first missing positive integer, we don't care non-positive integers, and we don't care about positive
integers that are relatively too large. Hence, we can utilize the space of the input array: 

__treat it as a container of size n__ and we want to rearrange elements such that most elements are in the place it should be.
We define that the first place is reserved for 1, the second place is reserved for 2, and so on. If there is such integer in the
array, we definitely should put that element to its destined place. If not, we can spare this place for other elements.

What need to be mentioned is that not all elements can be perfectly put to the place that is reserved for them, say -1, apparently
we don't have a place for this integer, or 9999999999, and our input array has size of only 10. So for such elements, we just 
place them to places that is not taken by their owners. 

After we rearrange the array, we can find the first missing positive integer with ease. Just check from the first to the end, and
find the first one that doesn't contain its owner. This element is the first missing positive integer.

The logic of this algorithm is as follows:
```c++
while (ptr < length of input array):
  if (the element is out of bound):
    ptr++
    continue
  else:
    if (this element is not in its reserved place and the element that is currently occupying the place is not equal to this element):
      swap these two elements
    else:
      ptr++

search the array to find the first element that is not placed in its position
```
