import numpy as np
class Solution:
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        if(len(position) == 0 or len(speed) == 0):
            return 0
        s = np.array(sorted(zip(position, range(len(position))), key = lambda x : x[0]))
        ref = s[:, 1]
        counter = len(position) - 1
        res = 0
        while(counter >= 0):
            time = (target - position[ref[counter]])/speed[ref[counter]]
            while(counter >= 0 and (target - position[ref[counter]])/speed[ref[counter]] <= time):
                counter -= 1
            res += 1
        return res
