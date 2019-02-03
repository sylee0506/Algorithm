# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        
        """
        ret = 99999
        stack = [(root, 1)]
        while stack:
            node, level = stack.pop()
            
            if node and not node.left and not node.right:
                ret = min(ret, level)
            
            if node:
                stack.append([node.left, level + 1])
                stack.append([node.right, level + 1])
        
        return ret ####DFS
        """
        queue = [(root, 1)]
        while queue:
            node, level = queue.pop(0)
            
            if node and not node.left and not node.right:
                return level
            
            if node:
                queue.append([node.left, level+1])
                queue.append([node.right, level+1]) #BFS ; faster than DFS
