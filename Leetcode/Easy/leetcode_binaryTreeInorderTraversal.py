'''
Leetcode Easy: 94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []

        def traverse(node):
            if not node:
                return
            
            if not node.left and not node.right: # leaf
                self.result.append(node.val)
                return
            
            traverse(node.left)
            self.result.append(node.val)
            traverse(node.right)

        traverse(root)
        return self.result