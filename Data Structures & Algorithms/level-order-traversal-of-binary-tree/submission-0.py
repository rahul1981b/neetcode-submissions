# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        q = deque()
        q.append(root)

        my_list = []
        level = 0
        while(len(q) > 0):
            new_list = []
            for i in range(0, len(q)):
                curr = q.popleft()
                new_list.append(curr.val)
                if curr.left is not None:
                    q.append(curr.left)
                if curr.right is not None:
                    q.append(curr.right)
            my_list.append(new_list)
            level +=1
        return my_list





