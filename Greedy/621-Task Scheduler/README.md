# Problem
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
```
Note:
* The number of tasks is in the range [1, 10000].
* The integer n is in the range [0, 100].

# Idea
The key to this problem is to find out the effect that cooling interval causes to the scheduling.

Gut tells us that cooling intervals must have connection with the number of all types of tasks, let the number of different types of tasks be denoted as `N`. 

How come? 

* If `n+1` is larger than or equal to `N`, it means that during a time period that lasts exactly `n`, then we can still do `N` different tasks in spite of vacant slots.
In this case, we can do the following:

⋅⋅⋅find out the most frequent task(s), say there are `F` most frequent tasks, and their frequency is `t`. Then we can know we need  `t` time
perids with length `n`, and the first `t-1` time slots can be filled in by all other types tasks (because their frequency is less than `t`).
The only thing we need to pay attention to is the last time period: we only need `F` time to complete all the tasks and we don't need empty slots behind them.

* If 'n+1' is less than 'N', it means that during a time period that lasts exactly `n`, we can always manage to schedule the tasks and make sure that
every same type tasks would have a cooldown interval between them. How so? We divide time into many time periods with length of `n`, and we start to put tasks into the slot. Our criteria are the following: 

⋅⋅⋅starting from the most frequent task, we put this task at the first slot of each time period; and then move to the next frequent task, we do the same thing. 
Since 'N' is greater than 'n', we can guarantee that when we fill out the first time period, we still have tasks that haven't yet been assigned. And we start from the 
first available slot, fill it and continue. The result would have two possibilities: 1. the time series is full without any empty slots inside, the result of 
this case is actually the length of the input! 2. the time series has some empty slots, but the calculation is the same as the upper case!

To sum up, the result would be the length or the first case answer, we choose the maximum!
