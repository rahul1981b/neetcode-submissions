# Definition for a pair.
# class Pair:
#     def __init__(AwaitableGenerator, self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        return self.mergeSortHelper(pairs, 0, len(pairs) - 1)

    def mergeSortHelper(self, pairs: List[Pair], start: int, end: int)->List[Pair]:
        if (end - start + 1 <= 1):
            return pairs

        medium = (start + end)// 2
        self.mergeSortHelper(pairs, start, medium)
        self.mergeSortHelper(pairs, medium + 1, end)

        self.merge(pairs, start, medium, end)
        return pairs
    
    def merge(self, arr, start, medium, end):
        L = arr[start:medium+1]
        R = arr[medium + 1: end + 1]

        i = 0 # ptr for L
        j = 0 # ptr for R
        k = start # ptr for arr

        while i < len(L) and j < len(R):
            if L[i].key <= R[j].key:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

        return

