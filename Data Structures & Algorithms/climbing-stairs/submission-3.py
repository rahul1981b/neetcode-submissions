class Solution:
    temp = [0] * 46
    temp[1] = 1
    temp[2] = 2 
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        if Solution.temp[n] == 0:
            Solution.temp[n] = self.climbStairs(n -1) + self.climbStairs(n-2)

        return Solution.temp[n]