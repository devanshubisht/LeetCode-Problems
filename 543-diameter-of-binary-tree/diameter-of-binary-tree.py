# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        maxDiam = [[0]]
        def dfs(node):
            if node == None:
                return 0
            leftVal = dfs(node.left)
            rightVal = dfs(node.right)
            maxDiam[0][0] = max(maxDiam[0][0], leftVal + rightVal)
            return max(leftVal + 1, rightVal + 1)
        dfs(root)
        return maxDiam[0][0]