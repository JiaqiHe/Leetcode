# Problem
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
* You must not modify the array (assume the array is read only).
* You must use only constant, O(1) extra space.
* Your runtime complexity should be less than O(n2).
* There is only one duplicate number in the array, but it could be repeated more than once.

## Idea 1
One common idea is to sort the given array and find the duplicate element.

## Idea 2
An innovative way of solving this problem is to treat the array as a linked list. The problem would transform into the following 
version:

Find the __starting point of cycle__ in a linked list ([leetcode 142](https://leetcode.com/problems/linked-list-cycle-ii/description/))

We use two pointers, one `fast` and one `slow`. Fast pointer goes two steps every time while slow pointer goes one step each time.
When they meet, we initialize another pointer starting from the very first of the array. We want this third pointer to meet slow
pointer. They each time go forward by 1 step. When they meet, the position where two pointers meet is the result.
