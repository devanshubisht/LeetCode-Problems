# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        
        def dfs(node):
            if node == None:
                return
            tempLeft = node.left
            node.left = dfs(node.right)
            node.right = dfs(tempLeft)
            return node
        
        dfs(root)

        return root
        