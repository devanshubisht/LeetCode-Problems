# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """

        if p.val > q.val:
            temp = q
            q = p
            p = temp

        def dfs(node):
            if node == None:
                return
            if q.val < node.val:
                return dfs(node.left)
            elif p.val > node.val:
                return dfs(node.right)
            else:
                return node
        return dfs(root) 