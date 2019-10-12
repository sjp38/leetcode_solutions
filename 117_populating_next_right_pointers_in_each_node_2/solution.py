"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
# key is level
last_nodes = {}
def trav(node, lv):
    if not node:
        return
    trav(node.left, lv + 1)
    node.next = None
    if lv in last_nodes:
        last_nodes[lv].next = node
    last_nodes[lv] = node
    trav(node.right, lv + 1)
        
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        trav(root, 0)
        return root
