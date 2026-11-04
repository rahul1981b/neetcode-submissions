# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):, final
#         self.key = key
#         self.value = value
class Solution:
    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        final_list = []
        l = len(pairs)

        if l == 0:
            return final_list

        final_list.append(pairs[:])
        
        for i in range(0,l -1):
            j = i + 1
            while j > 0 and pairs[j].key < pairs[j - 1].key:
                pairs[j], pairs[j -1] = pairs[j -1], pairs[j]
                j -= 1
            final_list.append(pairs[:])

        return final_list

     