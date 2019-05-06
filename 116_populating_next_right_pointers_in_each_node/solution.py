"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
def nth_level(node, level, target_level, nodes):
    if level == target_level:
        nodes.append(node)
        return
    nth_level(node.left, level + 1, target_level, nodes)
    nth_level(node.right, level + 1, target_level, nodes)
        
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        node = root
        level = 0
        while node:
            nodes = []
            nth_level(root, 0, level, nodes)
            for i in range(0,len(nodes) - 1):
                nodes[i].next = nodes[i + 1]
            node = node.left
            level += 1
        return root
