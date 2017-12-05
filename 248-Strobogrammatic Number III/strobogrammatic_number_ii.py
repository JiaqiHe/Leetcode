class Solution:
    def dfs(self, low, high, l, target):
        if l == 0:
            return [""]
        if l == 1:
            return ["0", "1", "8"]
        mid = self.dfs(low, high, l-2, target)
        res = []
        for s in mid:
            if l != target:
                res.append("0"+s+"0")
            res.append("1"+s+"1")
            res.append("6"+s+"9")
            res.append("8"+s+"8")
            res.append("9"+s+"6")
        return res
    
    def strobogrammaticInRange(self, low, high):
        """
        :type low: str
        :type high: str
        :rtype: int
        """
        self.minlen = min(len(high), len(low))
        self.maxlen = max(len(high), len(low))
        res = 0
        for l in range(self.minlen, self.maxlen+1):
            c = self.dfs(low, high, l, l)
            for s in c:
                if int(s) >= int(low) and int(s) <= int(high):
                    res += 1
        return res
