## Problem
A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

 

Example 1:
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```
Example 2:
```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
```
Example 3:
```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: 
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
``` 

Note:

* 1 <= target, startFuel, stations[i][1] <= 10^9
* 0 <= stations.length <= 500
* 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target

## Ideas
这道题乍一看感觉和[45. jump game II](https://leetcode.com/problems/jump-game-ii/description/)如出一辙，但其实是有区别的：

jump game里面，能跳的距离是不能攒着用的，一旦决定跳到哪个位置，不管还剩下多远的距离能跳，都是清零之后从这个位置重新起跳，跳跃的上限是该位置的数字。

对比这道题，这个油是可以攒着用的！只要燃油没有用掉，就算到了某个站点，这些油会被攒下来，之后可以继续用。

思路上，直觉的方法就是用个queue来记录状态，通过队列先进先出的性质来确保能得到最少停车次数到达终点。但是这个方法会TLE。

另外就是模仿jump game用greedy的想法。既然燃油能够攒下来，那么，我在哪里落脚其实不是很重要了，重要的是我要在路途中获得更多的燃油。所以可以用个priority
queue来做，存在路途范围之内的燃油量，每次挑那个最多的加到油箱里。如果pq都空了还没到终点，那就是到不了终点了。



