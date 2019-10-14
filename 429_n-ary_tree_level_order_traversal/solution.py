"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""

class Solution(object):
    ret = None
    def traverse(self, node, lv):
        if not node:
            return
        if len(self.ret) < lv + 1:
            self.ret.append([])
        self.ret[lv].append(node.val)
        for n in node.children:
            self.traverse(n, lv + 1)
            
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        self.ret = []
        self.traverse(root, 0)
        return self.ret
