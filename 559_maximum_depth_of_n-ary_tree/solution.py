"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        max_depth = 0
        to_visit = [(root, 1)]
        while len(to_visit):
            node, depth = to_visit[-1]
            del to_visit[-1]
            if not node:
                continue
            if max_depth < depth:
                max_depth = depth
            to_visit += [(n, depth + 1) for n in node.children]
        return max_depth
