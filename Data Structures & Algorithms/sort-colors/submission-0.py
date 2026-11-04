class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        counts = [0] * 3 #0,1,2
        for i in nums:
            counts[i] += 1
        
        i = 0
        for j in range(0, len(counts)):
            for k in range(0, counts[j]):
                nums[i] = j
                i += 1

           
        
