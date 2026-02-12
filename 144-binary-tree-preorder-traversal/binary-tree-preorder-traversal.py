# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def preorderTraversal(self, root):
        result = []
        
        def dfs(node):
            if not node: return
            
            result.append(node.val)   # Root
            dfs(node.left)            # Left
            dfs(node.right)           # Right
        
        dfs(root)
        return result
