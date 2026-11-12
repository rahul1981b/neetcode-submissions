class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = len(piles)
        m = max(piles)
        s = sum(piles) // h
        k = 0
        t = 0

        for i in range(1, m + 1):
            for j in range(0, l):
                num = piles[j]
                k += num // i
                if num % i != 0:
                    k += 1
                if j == (l - 1):
                    if k <= h:
                        return i
                    k = 0
                    break
                        
        return k
