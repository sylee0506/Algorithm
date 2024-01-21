'''
Leetcode Easy: 112. Path Sum
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        self.sum = 0

        def DFS(node):
            if not node: # edge case: partial path satisfies the condition => False
                return False
            else:
                self.sum += node.val

            if not node.left and not node.right:
                # leaf: check condition
                if self.sum == targetSum:
                    return True
                else:
                    self.sum -= node.val
                    return False

            # DFS(node)
            if DFS(node.left) == True:
                return True
            if DFS(node.right) == True:
                return True
            self.sum -= node.val
            
            return False
        
        if not root: # edge case: No nodes in tree => False
            return False
        return DFS(root)

        # pruning: assuming that there is no negative value, we can stop searching for the path when self.sum > targetSum