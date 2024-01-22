'''
Leetcode Medium: 113. Path Sum 2
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        # self.sum = 0
        self.path = []
        self.result = []

        def DFS(node):
            if not node:
                return
            else:
                # self.sum += node.val
                self.path.append(node.val)

            if not node.right and not node.left:
                if sum(self.path) == targetSum:
                    self.result.append(self.path)
                else:
                    self.path = self.path[:-1]
                    return

            DFS(node.left)
            DFS(node.right)
            self.path = self.path[:-1]

        if not root:
            return []
        DFS(root)
        return self.result

'''
# fast Python code
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        def dfs(node, path, cur):
            nonlocal res
            cur += node.val
            tmp = path + [node.val]
            if node.left:
                dfs(node.left, tmp, cur)
            if node.right:
                dfs(node.right, tmp, cur)
            if not node.left and not node.right and cur == targetSum:
                res.append(tmp)
        if not root:
            return []
        dfs(root, [], 0)
        return res
'''