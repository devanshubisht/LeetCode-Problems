# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return root
        result = []
        queue = []
        queue.append(root)

        while (len(queue) > 0):
            res = []
            l = len(queue)
            for i in range(l):
                first = queue.pop(0)
                res.append(first.val)
                if first.left != None:
                    queue.append(first.left)
                if first.right != None:   
                    queue.append(first.right)
            result.append(res)
        return result
                
                