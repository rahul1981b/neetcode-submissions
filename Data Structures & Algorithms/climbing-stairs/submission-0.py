class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        return climbStairs(self, n -1) + climbStairs(self, n-2)