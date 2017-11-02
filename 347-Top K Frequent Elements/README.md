# Problem
Given a non-empty array of integers, return the k most frequent elements.

For example,

Given `[1,1,1,2,2,3]` and k = 2, return `[1,2]`.

Note: 

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.

Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Idea
This problem wants us to output the most frequent k integers, and the first thought is to count every integer's appearances, sort them and 
select the top k ones. However, storing this info requires trick. Appearently we need a pair to store integers and their occurances. Hence,
we can use `unordered_map` to temporarily count the numbers. But sorting info within an unordered_map is impossible. We need to take info out
into some other data structures like vectors. We can do so, but we can use a smart data structure `priority_queue`, and customize our own 
priority queue such that it will output the most frequent element every time we peek the top if it.

Below is the construction and declaration of a customized priority queue:
```c++
    class Compare {
        public: 
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        }
    };
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pri;
 ```
