# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        my_list = []
        if not root:
            return []

        q = deque()
        q.append(root)
        while(len(q) > 0):
            right_side = None
            for i in range(0, len(q)):
                curr = q.popleft()
                if curr:
                    right_side = curr
                    q.append(curr.left)
                    q.append(curr.right)
            if right_side:
                my_list.append(right_side.val)
        return my_list