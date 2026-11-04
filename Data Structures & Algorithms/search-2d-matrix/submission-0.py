class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        lm = len(matrix)
        for i in range(0, lm):
            temp = matrix[i]
            l,r = 0, len(temp) -1

            while (l <= r):
                mid = int((l + r)/2)
                if target > temp[mid]:
                    l = mid + 1
                elif target < temp[mid]:
                    r = mid - 1
                else:
                    return True
         
        return False