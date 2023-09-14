# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        res = []
        queue = []
        queue.append(root)
        while(len(queue)>0):
            l = len(queue)
            for i in range(l):
                first = queue.pop(0)
                if i == l-1:
                    res.append(first.val)
                if first.left:
                    queue.append(first.left)
                if first.right:
                    queue.append(first.right)
        return res


        
## at each level the most right one