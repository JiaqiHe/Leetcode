# Problem
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

## Idea
* 本题属于binary search
* 我们想要找一个数，如果没找到，我们只能接受比它小的
* 属于“如果没search到，则输出比目标值小的最大元素的index”类型
* 
* 思路：
* 首先对citations进行降序排序，然后我们要找的是满足 citations[i] > i+1 的最大的i


![](https://github.com/JiaqiHe/Leetcode/blob/master/274-H-Index/demo.png)
