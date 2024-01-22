'''
Leetcode Medium: 515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []
        self.currLevelQueue = []
        self.nextLevelQueue = []

        if not root:
            return []
        self.currMax = root.val
        self.currLevelQueue.append(root)

        while len(self.currLevelQueue) > 0:
            node = self.currLevelQueue.pop()
            if node.val > self.currMax:
                self.currMax = node.val

            if node.left:
                self.nextLevelQueue.append(node.left)
            if node.right:
                self.nextLevelQueue.append(node.right)

            if len(self.currLevelQueue) == 0:
                self.result.append(self.currMax)
                if len(self.nextLevelQueue) == 0:
                    break
                self.currLevelQueue = self.nextLevelQueue
                self.currMax = self.nextLevelQueue[0].val
                self.nextLevelQueue = []

        return self.result