# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    answer = None
    def trav(self, node, lv):
        if not node:
            return
        
        if len(self.answer) == lv:
            self.answer.append([])
        level_nodes = self.answer[lv]
        
        level_nodes.append(node.val)
        
        self.trav(node.left, lv + 1)
        self.trav(node.right, lv + 1)
        
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.answer = []
        self.trav(root, 0)
        return self.answer
