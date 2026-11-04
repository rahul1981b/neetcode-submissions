# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        return self.quickSortHelper(pairs, 0, len(pairs) - 1)
    
    def quickSortHelper(self, pairs: List[Pair], start: int, end: int) -> List[Pair]:
        if (start >= end):
            return pairs
        
        pivot = pairs[end]

        i    = start
        left = start

        while i < end:
            if pairs[i].key < pivot.key:
                pairs[left],pairs[i] = pairs[i], pairs[left]
                left += 1
            i += 1
        pairs[end],pairs[left] = pairs[left], pairs[end]
        
        self.quickSortHelper(pairs, start, left -1)
        self.quickSortHelper(pairs, left + 1, end)
        return pairs

