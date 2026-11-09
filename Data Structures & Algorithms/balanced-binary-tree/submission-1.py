# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def treeHight(root) -> int:
            if not root:
                return -1
            
            h_left  = treeHight(root.left)
            h_right = treeHight(root.right)
            return max(h_left, h_right) + 1
    
        if not root:
            return True
        
        diff = treeHight(root.left) - treeHight(root.right)
        if diff < -1 or diff > 1:
            return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)
        