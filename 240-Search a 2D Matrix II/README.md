# Problem
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

## Idea
The brute force approach is to go through every element in the matrix and compare it with the element to be found, in this case, 
the time complexity is O(mn) since there are m×n elements in total.

However, this brute force algorithm doesn’t use the property that each row and column is sorted in ascending order. We should definitely 
harness this property to improve the algorithm.
How could sorting help us better solve this problem? If we think about 1D array first, we would know that if the array is sorted, 
we can use binary search to achieve an O(lgn) time complexity algorithm to find a specific element. Similarly, for 2D matrix, we can 
apply similar idea to solve this problem:

* We first locate on the last element of the first row, namely the top right element, we name the pointer that points to this element ptr, 
compare it with the element we want to find, name it elem_to_find
* If matrix[ptr] < elem_to_find, then let ptr point to the element below the previous one; else, let ptr point to the element which is 
left to the previous one (if at any time, ptr goes out of the range of matrix, then it indicates there is no elem_to_find in the matrix). 
After updating the ptr, we repeat b) until we find elem_to_find.

In this case, we can know that the elements that we have visited would be at most m+n, hence, the time complexity of this algorithm is O(n).
