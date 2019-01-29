# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        self.getSum(root)
        return self.ans
    
    def getSum(self, root):
        if root == None:
            return 0
        else:
            left, right = self.getSum(root.left), self.getSum(root.right)
            self.ans += abs(left - right)
            return left + right + root.val
